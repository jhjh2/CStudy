#include <stdio.h>

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

	printf("stat 함수 호출 횟수 : %d\n", iCall);

	g_iStatic = 100;
	// 외부 변수
	g_iExtern = 500;

	print_i();

	return 0;
}