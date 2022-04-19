// C...   : 컴파일 에러
// LNK... : 링크 단계 에러

#include "func.h"
#include "common.h"

#include <stdio.h>

//int g_i = 0; // 링크 에러! variables.cpp에 이미 선언된 전역 변수이다
//static int g_iStatic = 0; // 에러 발생하지 않음.

// 분할 구현
int add(int a, int b)
{
	g_iStatic; // variables_func.cpp 파일에 선언된 정적 변수를 의미

	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

// 외부 변수
int g_iExtern = 0; // 어떠한 .cpp 파일에서 초기화 되어도 문제 없다

void print_i()
{
	printf("g_iStatic의 값 : %d\n", g_iStatic);
	printf("g_iExtern의 값 : %d\n", g_iExtern);
}