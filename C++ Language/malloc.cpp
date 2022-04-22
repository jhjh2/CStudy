#include <iostream>

#include "arr.h"

// 변수
// 지역(스택)
// 전역, 정적, 외부(데이터)

// 메모리 영역
// 스택
// 데이터
// ROM
// 힙 영역(동적 할당)
int g_i = 100;

typedef struct _tagST {
	//int iArr[g_i];
}ST;

int main()
{
	int* pInt = (int*)malloc(100); // 힙 메모리 시작 지점 void 타입으로 반환
	float* pFloat = (float*)pInt;

	*pFloat = 2.4f;
	int i = *pInt;

	// 동적 할당
	// 1. 런타임 중에 대응 가능
	// 2. 사용자가 직접 메모리 관리(할당, 해제)

	int iInput = 0;
	scanf_s("%d", &iInput);

	int* pI = nullptr;

	if (100 == iInput)
	{
		pI = (int*)malloc(100);
	}

	if (nullptr != pI)
	{
		free(pI);
	}

	// 가변 배열
	int a = 100;
	scanf_s("%d", &a);

	// 배열 개수를 선언할 때에는 변수를 사용할 수 없다
	//int arr[a] = {}; // 스택 메모리를 얼마나 사용할지 정해지지 않기 때문에 변수로 배열을 선언할 수 없다

	// 객체(Instance)
	tArr arr1 = {};
	tArr arr2 = {};
	tArr arr3 = {};
	
	/* 구조체 초기화
	s.pInt = (int*)malloc(8);
	s.iCount = 0;
	s.iMaxCount = 10;
	*/

	// 배열 초기화 함수
	initArr(&arr1);
	initArr(&arr2);
	initArr(&arr3);

	// 객체 arr1, arr2, arr3는 지역 변수로 자동으로 해제가 된다
	// 

	// 데이터 추가 함수
	for (int i = 0; i < 10; ++i)
	{
		pushBack(&arr1, i);
	}

	// 출력
	for (int i = 0; i < arr1.iCount; ++i)
	{
		printf("%d\n", arr1.pInt[i]);
	}
	
	// 배열 메모리 해제 함수
	releaseArr(&arr1);
	releaseArr(&arr2);
	releaseArr(&arr3);


	return 0;
}