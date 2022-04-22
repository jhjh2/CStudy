#include <stdio.h>
#include <wchar.h>
#include <cassert>

// 변수의 종류
// 1. 지역변수 - 스택 영역
// 2. 전역변수 - 데이터 영역
// 3. 정적변수(static) - 데이터 영역
// 4. 외부변수(extern) - 데이터 영역

// 메모리 영역
// 1. 스택 영역
// 2. 데이터 영역
// 3. 읽기 전용(코드, ROM)
// 4. 힙 영역


// 전역변수
int g_i = 0; // 데이터 영역

// Data 영역 특징
// 프로그램 시작 시 생성
// 프로그램 종료 시 해제

void test()
{
	int i = 0; // 지역 변수 - 스택 영역
	++i;
	//a = 100;
}

void test1()
{
	++g_i;
	//a = 100; // 오류 발생! test1 함수에는 a 지역 변수가 없다
}

// 분할 구현
// 함수 선언은 func.h 파일, 함수 구현은 func.cpp 파일
#include "func.h"
#include "common.h"

// #include "func.h"의 의미
// func.h의 코드를 가져온다

//int add(int a, int b)
//int sub(int a, int b);
//int mul(int a, int b);

// 정적 변수
//static int g_iStatic = 0; // 데이터 영역

// 정적 변수와 전역 변수의 차이
// 정적 변수는 선언된 .cpp 파일 내부에서만 인식된다

// 정적 변수가 함수 안에 선언되는 경우
// 함수 안에서만 호출할 수 있다
// 함수가 종료되어 스택 메모리가 해제되어도 정적 변수는 데이터 메모리에 남아있다
// 정적 변수 초기화는 최초 초기화 이후에는 실행되지 않는다
int stat()
{
	static int l_iStatic = 0; // 데이터 영역
	int a = 0; // 스택 영역
	++l_iStatic;

	return l_iStatic;
}

void point(int* a)
{
	*a = 500;
}

void output(const int* pInt)
{
	int i = *pInt; // 접근하여 확인 가능
	//*pInt = 200; // 값 수정은 불가능

	// 강제 형변환 하여 값 수정은 가능하다
	// const는 함수를 설계한 사람의 의도를 나타낸다
	int* pI = (int*)pInt;
	*pI = 1000;
}

unsigned int getLength(const wchar_t* _pStr)
{
	int i = 0;

	/*
	while (1)
	{
		wchar_t c = *(_pStr + i); // == wchar_t c = _pStr[i]

		if (c == 0) // == if (c == '\0')
		{
			break;
		}

		++i;
	}
	*/

	while ('\0' != _pStr[i])
	{
		++i;
	}

	return i;
}

void strCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	// 예외처리
	// 이어붙인 최종 문자열 길이가 목적지 저장 공간을 넘어서는 경우
	int iDestLen = getLength(_pDest);
	int iSrcLen = getLength(_pSrc);
	if (_iBufferSize < iDestLen + iSrcLen + 1) // +1은 null 문자 공간
	{
		assert(nullptr);
	}

	// 문자열 이어 붙이기
	// 1. Dest 문자열의 끝을 확인
	iDestLen;
	// 2. 반복적으로 Src 문자열을 Dest 문자열 끝 위치에 복사하기
	// 3. Src 문자열의 끝을 만나면 반복 종료
	for (int i = 0; i < iSrcLen + 1; ++i)
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int strCmp(const wchar_t* _left, const wchar_t* _right)
{
	int i = 0;
	int leftLen = getLength(_left);
	int rightLen = getLength(_right);

	int iLoop = leftLen < rightLen ? leftLen : rightLen;

	// 1. 반복문을 도는 동안 판별되는 경우
	for (int i = 0; i < iLoop; ++i)
	{
		if (_left[i] < _right[i])
		{
			return -1;
		}
		else if(_left[i] > _right[i])
		{
			return 1;
		}
	}

	// 2. 반복문을 도는 동안 일치하는 경우
	if (leftLen == rightLen)
	{
		return 0;
	}
	else if (leftLen < rightLen)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

typedef struct _tagMyST {
	int a;
	float f;
}MYST;

int main()
{
	// 지역변수
	int a = 0;

	test(); // 함수는 지역변수 int a에 접근할 수 없다
	test();
	test();

	test1(); // 함수는 전역변수 int g_i에 접근할 수 있다
	test1();
	test1();

	int h = add(10, 20); // 링크 단계에서 variables_func.cpp 파일에 구현된 함수가 연결된다

	h = mul(10, 20);

	// 헤더 파일에 함수 선언만 하는 이유
	// 컴파일 단계에서는 .cpp 파일 단위로 컴파일이 진행된다 -> .obj
	// 링크 단계에서 여러 .obj 파일이 하나로 합쳐지기 때문에
	// 헤더 파일에 직접 함수를 구현하면 함수가 중복 구현되는 것과 같다
	
	// 분할 구현의 문제점
	// 코드 작성 단계에서, 한 .cpp 파일에서 선언한 전역 변수의 존재를 다른 .cpp 파일에서 알 수 없다
	// 헤더 파일에 전역변수를 선언하면 마찬가지로 링크 단계에서 중복 선언 에러가 발생한다

	g_iStatic; // variables.cpp 파일에 선언된 정적 변수를 의미

	stat();
	//l_iStatic; // 함수 밖에서 호출할 수 없다

	g_i = 0;
	printf("test1 함수 호출 횟수 : %d\n", g_i); // 0 (실제 횟수는 3), 전역 변수는 접근이 가능하여 값이 조작될 수 있다

	stat();
	stat();
	stat();
	stat();
	int iCall = stat();

	printf("stat 함수 호출 횟수 : %d\n", iCall); // 6

	g_iStatic = 100;
	// 외부 변수
	g_iExtern = 500;

	print_i();

	// 포인터 변수
	// 주소를 저장하는 변수
	// 자료형* + 변수명 
	int* pInt = nullptr; // int*은 해당 포인터에 전달된 주소를 해석하는 방식과 메모리 크기 단위를 의미

	int i = 100;

	int* pi = &i; // pi 변수에 i 변수의 주소를 저장

	// 주소로 접근
	*pi = 100; // i 변수에 100을 대입

	// 주소의 단위 Byte
	// 주소의 표현은 정수 -> 100.5 불가
	// int의 경우 4씩 증가 -> ex) 100 104 108 ...

	float f = 3.f;

	pi = (int*)&f; // 강제 형변환 하여 포인터 변수에 주소값을 저장
	i = *pi; // f 변수에 저장된 비트가 그대로 i 변수에 저장되고 int 방식으로 해석된다 == 큰 정수가 i 변수에 저장된다

	// 포인터 변수의 메모리 크기
	// 운영체제의 명령어 처리 단위에 따라 달라진다 : 32bit -> 4Byte, 64bit -> 8Byte
	// 윈도우 64bit에서는 8Byte이다
	int iSize = sizeof(int*); // 8
	iSize = sizeof(pi);

	char* pChar = nullptr;
	short* pShort = nullptr;

	// 포인터 주소의 증감 단위
	// 자료형의 크기에 따라 달라진다
	pInt = &i;
	pInt += 1; // 다음 int 위치로 이동 : 100 -> 104
	// pInt는 int* 변수이기 때문에 가리키는 곳을 int로 해석한다
	// 따라서 주소값을 1 증가하는 의미는 다음 int 위치로 접근하기 위해 sizeof(int) 단위로 증가하게 된다

	// 포인터와 배열
	// 배열의 특징
	// 1. 메모리가 연속적인 구조이다
	// 2. 배열의 이름은 배열의 시작 주소이다
	int iArr[10] = {};

	// int 단위로 접근
	*(iArr + 0) = 10; // == iArr[0] = 10;
	*(iArr + 1) = 10; // == iArr[1] = 10;

	int p = 100;

	point(&p);

	printf("출력 : %d", p); // 500

	//scanf_s("%d", &p); // scanf 함수는 콘솔창에 입력된 데이터를 변수에 저장할 때 주소로 접근한다

	// const
	// 상수화
	// r-value : 상수
	// l-value : 변수
	volatile const int cInt = 100; // 문법적으로 상수 취급
	// volatile : 최적화 연산 사용 금지 -> cpu 레지스터에 저장된 값을 불러오는 것을 방지

	// 포인터로 메모리에 직접 접근하여 수정 가능
	pInt = (int*)&cInt;
	*pInt = 300;
	printf("cInt 출력 : %d", cInt); // 300

	// const와 pointer
	int d = 0;
	int e = 0;
	pInt = &d;

	*pInt = 1; // *pInt == *(&d) == d = 1;
	pInt = nullptr; // 포인터 변수가 가리키는 대상을 변경할 수도 있다

	// const의 위치에 따라 결과가 달라진다
	// 1. 포인터 변수가 가리키는 대상을 상수화
	const int* pConstInt = &d;
	//*pConstInt = 100; // 오류 발생! d 변수에 저장된 값을 변경할 수 없다
	pConstInt = &e;
	
	// 2. 포인터 변수를 상수화
	int* const pIntConst = &d;
	*pIntConst = 100;
	//pIntConst = &e; // 오류 발생! 포인터 변수의 값을 변경할 수 없다

	// 3. 포인터 변수와 포인터가 가리키는 변수 모두 상수화
	const int* const pConstIntConst = nullptr; 
	//*pConstIntConst = 100; // 포인터 변수가 가리키는 대상의 값을 바꿀 수 없고,
	//pConstIntConst = &e; // 포인터 변수의 값을 바꿀 수 없다

	// const는 포인터의 기능만 제한할 뿐이다
	{
		int a = 0;
		const int* pInt = &a;
		//*pInt = 100;

		a = 100; // a 변수의 값을 변경할 수 있다

		int* p = &a;
		*p = 100;
	}

	// 함수에 주소를 전달
	// output 함수의 스택 메모리 영역에 전달한 대상을 복제하는 대신 주소를 전달하여 main 함수의 스택 메모리 영역에 접근
	// 전달하는 대상의 크기가 큰 경우 효율적이다
	a = 100;
	output(&a);

	// void 포인터
	// 1. 원본의 자료형을 정하지 않음
	// 2. 어떠한 타입의 변수의 주소든 저장 가능
	// 3. 역참조 불가능
	// 4. 주소 연산 불가능
	void* pVoid = nullptr;

	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		// 원본으로 접근을 했을 때 해석 방식을 정하지 않아 어떠한 주소도 저장 가능
		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;

		//*pVoid; // 해석을 하지 않기 때문에 역참조가 불가능하다
		//*pVoid + 1;
	}

	{
		// 문자
		// char(1Byte), wchar(2Byte)
		char c1 = 0; // 2진수 0을 메모리에 저장하고, 'null 문자'로 해석된다
		char cc = '1'; // '문자 1'에 해당하는 2진수 49를 메모리에 저장하고, '문자 1'로 해석된다

		wchar_t wc1 = 49; // 2진수 49를 메모리에 저장하고, '문자 1'로 해석된다
		short s = 49; // 2진수 49를 메모리에 저장하고, 정수 49로 해석된다

		char c = 'a';
		wchar_t wc = L'a'; // L은 한 문자 당 2Byte로 표현함을 의미

		// 문자열
		// 문자열의 마지막에는 'null 문자'가 들어가 문자열의 끝을 알린다
		char szChar[10] = "abcdef"; // index 7에 null 문자가 있다

		wchar_t szWChar[10] = L"abcdef";
		wchar_t szWChar1[10] = { 97, 98, 99, 100, 101, 102, };
		
		// 문자열은 주소값이므로 포인터 변수에 저장 가능하다
		//wchar_t* pWChar1 = L"abcdef"; // 오류 발생! L문자열의 반환 타입은 const wchar_t이다
		const wchar_t* pWChar = L"abcdef";
		//wchar_t* pWChar1 = (wchar_t*)L"abcdef"; // 강제 형변환으로는 가능하나 프로그램 실행 도중 오류가 발생한다

		szWChar[1] = 'z'; // 문자열을 복사해온 배열을 수정
		//pWChar[1] = 'z'; // 문자열 자체를 수정하려는 의도
		// 코드가 실행되는 도중 변경하려는 아이러니한 상황
		// 문자열은 읽기전용 메모리에 저장되고 보호된다

		// 표준
		char szTest[10] = "abc한글"; // 멀티바이트(표준x), L이 없는 경우 문자에 따라 가변길이로 표현함
		wchar_t szTestW[10] = L"abc한글"; // 와이드바이트가 표준이다 == 유니코드

		// 문자열의 길이
		wchar_t szName[10] = L"Raimond";

		int iLen = wcslen(szName); // 7, null 문자는 포함되지 않는다

		// 문자열 길이 리턴하는 함수 직접 만들기
		iLen = getLength(szName);

		// 문자열 이어 붙이기
		wchar_t szString[10] = L"abc";

		wcscat_s(szString, 10, L"def");

		// 문자열 붙이는 함수 만들기
		strCat(szString, 10, L"ghi");

		int iRet = wcscmp(L"ca", L"ca");
		iRet = strCmp(L"abc", L"abcde");
		
	}

	{
		// 구조체와 포인터
		MYST s = {};

		s.a;

		MYST s2;
		MYST s3;

		MYST* pST = &s;
		pST + 1; // +1은 sizeof(MYST)만큼 증가

		(*pST).a = 100;
		(*pST).f = 3.14f;

		pST->a = 100;
		pST->f = 3.14f;
	}

	return 0;
}