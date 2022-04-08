#include <stdio.h>

// 함수 선언
void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int main(void)
{
	// 포인터

	// 철수 = 101호 -> 메모리 공간의 주소
	// 영희 = 201호
	// 민수 = 301호
	// 각 문 앞에 '암호'가 걸려 있음
	int 철수 = 1; // 암호
	int 영희 = 2;
	int 민수 = 3;

	printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
	printf("철수네 주소 : %d, 암호 : %d\n", &영희, 영희);
	printf("철수네 주소 : %d, 암호 : %d\n", &민수, 민수);

	// 미션맨
	// 첫 번째 미션 : 아파트의 각 집에 방문하여 문에 적힌 암호 확인
	int* 미션맨; // 포인터 변수
	미션맨 = &철수;
	printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &영희;
	printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &민수;
	printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	// 두 번째 미션 : 각 암호에 3을 곱하라
	미션맨 = &철수;
	*미션맨 *= 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &영희;
	*미션맨 *= 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &민수;
	*미션맨 *= 3;
	printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	// 스파이
	// 미션맨이 바꾼 암호에서 2를 빼라

	int* 스파이 = 미션맨;
	printf("\n스파이가 미션을 수행하는 중...\n");
	스파이 = &철수;
	*스파이 = *스파이 - 2; // 철수 = 철수 - 2;
	printf("스파이가 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	스파이 = &영희;
	*스파이 = *스파이 - 2; // 철수 = 철수 - 2;
	printf("스파이가 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	스파이 = &민수;
	*스파이 = *스파이 - 2; // 철수 = 철수 - 2;
	printf("스파이가 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	printf("\n철수, 영희, 민수가 집에 오고서는 바뀐 암호를 보고 놀람!\n");
	printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
	printf("철수네 주소 : %d, 암호 : %d\n", &영희, 영희);
	printf("철수네 주소 : %d, 암호 : %d\n", &민수, 민수);

	// 참고로 미션맨과 스파이가 사는곳의 주소는 &미션맨으로 확인
	printf("미션맨의 주소 : %d\n", &미션맨);
	printf("스파이의 주소 : %d\n", &스파이);

	// 배열
	int arr[3] = { 5, 10, 15 };
	int* ptr = arr; // arr은 arr배열의 첫 주소값을 가지고 있다
	for (int i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값 : %d\n", i, ptr[i]); // 포인터는 배열의 주소값을 그대로 가지고 있음
	}
	ptr[0] = 100;
	ptr[1] = 200;
	ptr[2] = 300;
	for (int i = 0; i < 3; i++)
	{
		//printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
		printf("배열 arr[%d]의 값 : %d\n", i, *(arr + i));
	}

	for (int i = 0; i < 3; i++)
	{
		//printf("포인터 ptr[%d]의 값 : %d\n", i, ptr[i]);
		printf("배열 ptr[%d]의 값 : %d\n", i, *(ptr + i));
	}

	// *(arr + i) == arr[i]
	// arr == arr 배열의 첫번째 값의 주소 == &arr[0]
	printf("arr 자체의 값 : %d\n", arr);
	printf("arr[0]의 주소 : %d\n", &arr[0]);

	printf("arr 자체의 값이 가지는 주소의 실제 값 : %d\n", *arr); // *(arr + 0)
	printf("arr[0]의 실제 값 : %d\n", *&arr[0]); // arr[0]

	// *&는 아무것도 없는 것과 같다. &는 주소이며, *는 그 주소의 값이다.
	printf("arr[0]의 실제 값 : %d\n", *&*&*&*&*&*&*&*&*&*&arr[0]);
	printf("arr[0]의 실제 값 : %d\n", arr[0]);

	// SWAP
	int a = 10;
	int b = 20;
	printf("a의 주소 : %d\n", &a);
	printf("b의 주소 : %d\n", &b);

	// a와 b의 값을 바꾼다.
	printf("swap 함수 전 -> a : %d, b : %d\n", a, b);
	swap(a, b);
	printf("swap 함수 후 -> a : %d, b : %d\n", a, b); // 변경되지 않았다.

	// 값에 의한 복사 (Call by Value) -> 값만 복사한다는 의미

	// 메모리 공간의 주소값을 넘겨 
	printf("주소값 전달swap 함수 전 -> a : %d, b : %d\n", a, b);
	swap_addr(&a, &b);
	printf("주소값 전달swap 함수 후 -> a : %d, b : %d\n", a, b);

	// 배열일 때, arr2 -> 주소
	int arr2[3] = { 10, 20, 30 };
	changeArray(arr2); // changeArray(&arr2[0]);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}

	return 0;
}

// 함수 정의
void swap(int a, int b)
{
	printf("swap 함수 내 a의 주소 : %d\n", &a);
	printf("swap 함수 내 b의 주소 : %d\n", &b);

	int temp = a;
	a = b;
	b = temp;
	printf("swap 함수 내 -> a : %d, b : %d\n", a, b);
}

void swap_addr(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("주소값 전달swap 함수 내 -> a : %d, b : %d\n", *a, *b);
}

void changeArray(int* ptr)
{
	ptr[2] = 50;
}