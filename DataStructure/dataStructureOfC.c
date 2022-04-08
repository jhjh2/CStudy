#include <stdio.h>
#include <stdlib.h>

/* C 언어에서 제공하는 데이터를 저장하는 구조*/

// 1. 배열 Array
// 2. 구조체 struct
// 3. 포인터 pointer

int main(void)
{
	/* 배열 : 동일한 data type의 연속 */
	int arr[2][2] = { // int = 4byte, 주소값이 4씩 증가
		{1,2},
		{3,4}
	};

	// 순차적으로 저장
	printf("%d, %d, %d, %d", &arr[0][0], &arr[0][1], &arr[1][0], &arr[1][1]);

	printf("\n");

	char arrc[2][2] = { // char = 1byte, 주소값이 1씩 증가
		{'a','b'},
		{'c','d'}
	};

	// 순차적으로 저장
	printf("%d, %d, %d, %d", &arrc[0][0], &arrc[0][1], &arrc[1][0], &arrc[1][1]);


	/* 구조체 : 이종 data type을 모아 새로운 data type 창조 */
	struct A {
		int i;
		char c;
	};

	// 대입 assignment 가능
	struct A M, N;
	M.i = 10;
	M.c = 'c';

	N = M;

	// 하지만 두 구조체의 비교는 불가능
	// if (M == N) { } 오류 발생!
	if (M.i == N.i && M.c == N.c) {}

	// struct와 typedef
	typedef int I; // int a1 == I a1

	typedef struct B {

	} BB; // struct B b1 == BB b1

	// 익명 구조체
	typedef struct {

	}CC; // 데이터타입 CC로 호출 가능

	// 자기참조 구조체 Self Referential Structure
	struct C {
		int x;
		struct C* k; // 포인터만 올 수 있다
	};


	/* 포인터 */
	int a;
	a = 55;

	int* b;
	b = &a;

	int** c;
	c = &b;

	// **c = **(&b) = *b = *(&a) = a
	printf("%d", **c); // 55, a에 저장된 값

	// 포인터와 Memory Allocation
	// void* malloc(할당받을 크기)
	// void*는 주소를 반환한다는 의미, 일정한 타입이 없어 원하는 형태로 바꿔 사용 가능
	// malloc() 함수는 heap 영역에 할당하기 때문에 free()함수로 해제를 해야 한다

	// 10개의 정수 저장할 공간 할당 후 메모리 주소 반환
	int* aa = (int*)malloc(10 * sizeof(int)); // aa에는 할당된 메모리의 시작주소가 저장됨

	// void free(포인터주소)
	free(aa);

	return 0;
}
