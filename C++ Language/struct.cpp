#include <stdio.h>

// 사용자 정의 자료형
typedef struct _tagMyST {
	int a;
	float f;
}MYST;

typedef struct _tagBig {
	MYST k;
	int i;
	char c;
}BIG;

typedef int INT;

struct NewStruct {
	int a;
	short s;
};

typedef struct NewStruct2 { // c, c++ 모두 사용 가능
	int a;
	short s;
}NEWST;

int main()
{
	// 구조체
	MYST t;
	t.a = 10;
	t.f = 10.2312f;

	int iSize = sizeof(MYST); // 8

	INT i;

	struct NewStruct a;
	NEWST b;

	NewStruct c; // c 컴파일러에서는 에러 발생, c++ 컴파일러에서는 사용 가능

	// 구조체 초기화
	MYST t2 = { 100, 3.14f };

	return 0;
}