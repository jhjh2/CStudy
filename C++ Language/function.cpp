#include <stdio.h>

// 변수
// 1. 지역변수
// 2. 전역변수
// 3. 정적변수
// 4. 외부변수

// 전역변수
int global = 0;

int add(int left, int right)
{
	return left + right;
}

int factorial(int _iNum)
{
	int iValue = 1;

	for (int i = 0; i < _iNum - 1; ++i)
	{
		iValue *= (i + 2);
	}

	return iValue;
}

int factorial_re(int _iNum)
{
	if (_iNum == 1)
	{
		return 1;
	}

	return _iNum * factorial_re(_iNum - 1);
}

int fibonacci(int _iNum)
{
	int iValue = 0;
	int iPrev1 = 1;
	int iPrev2 = 1;

	for (int i = 0; i < _iNum - 2; ++i)
	{
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}

	return iValue;
}

int fibonacci_re(int _iNum)
{
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}

	return fibonacci_re(_iNum - 1) + fibonacci_re(_iNum - 2);
}

// 함수
int main()
{
	// 지역변수
	// 괄호 안에 선언된 변수(함수, 지역)
	int local = 10 + 20;

	{
		int local = 100;

		local; // 같은 지역의 우선순위가 높다
		{
			// 지역 안에 또 지역 생성 가능
		}
	}

	int data = 0;

	// 함수
	data = add(10, 20);

	// 반복문
	int i = 100;
	for (int i = 0; i < 5; ++i) // for문 안의 int i는 for문의 지역변수
	{
		if (i % 2 == 1)
		{
			continue;
		}

		printf("Output Test\n");
	}

	int j = 0;
	while (j < 5)
	{
		if (j % 2 == 1)
		{
			break;
		}

		printf("Output Test\n");

		++j;
	}

	// 콘솔
	// printf
	printf("abcdef %d \n", 10);
	printf("abcdef %f \n", 3.14f);

	for (int i = 0; i < 10; ++i)
	{
		printf("Output i : %d \n", i);
	}

	// scanf
	int iInput = 0;
	printf("Insert number : ");
	scanf_s("%d", &iInput);

	// 함수가 사용하는 메모리 영역
	// 스택 메모리 영역
	// 함수의 호출 과정이 스택과 유사하다, FILO
	int iData = add(100, 200); // add(int left, int right) 함수는 left와 right 변수가 메모리에 할당된다
	iData = add(300, 400); 
	iData = add(222, 700); // 함수가 호출 시 스택 메모리가 할당되고,
	iData = add(333, 555); // 함수가 종료 시 스택 메모리가 해제된다

	// Factorial
	int iValue = factorial(4);
	iValue = factorial(10);

	// Debug 시 호출스택(Call Stack)과 로컬(Locals)을 사용하여 메모리의 상태를 확인할 수 있다
	// 함수 종료 후 리턴값은 cpu의 레지스터에 저장된다

	// 재귀함수
	// 재귀함수 호출 시 새로운 스택 메모리를 할당한다
	// 재귀함수에 탈출조건이 없으면 스택 오버플로우 발생
	// 장점 : 가독성, 구현의 용이
	// 단점 : 성능이 떨어진다(함수 호출, 해제 비용)

	// 재귀함수 팩토리얼
	iValue = factorial_re(10);

	// 피보나치 수열
	// 1 1 2 3 5 8 13 21 34 55 ...
	iValue = fibonacci(3);
	
	// 재귀함수 피보나치
	iValue = fibonacci_re(3);

	// 배열
	int iArray[10] = { }; // [ 0 0 0 0 0 0 0 0 0 0 0 ], 0으로 초기화됨

	//iArray[10] = 10; // 잘못된 메모리 주소에 접근 주의
	iArray[9] = 10;

	return 0;
}