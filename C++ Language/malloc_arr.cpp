#include "arr.h"

#include <iostream>

void initArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2); // 힙 메모리 영역 8Byte 할당 후 시작 주소값 반환
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

void reAlloc(tArr* _pArr)
{
	// 1. 메모리 동적 할당
	// 힙 영역을 2칸씩 추가로 할당받아 이어붙일 수 없으므로
	// 재할당 시 기존 크기의 2배씩 새로 할당 받는다
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존 공간 해제
	free(_pArr->pInt);

	// 4. 배열이 새로 할당된 공간을 가리키게 한다
	_pArr->pInt = pNew;

	// 5. MaxCount 변경
	_pArr->iMaxCount *= 2;
	
}

void pushBack(tArr* _pArr, int _iData)
{
	// 힙 영역에 할당한 공간이 다 찬 경우
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// 재할당
		reAlloc(_pArr);
	}

	// 데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData; // 데이터 대입 후 iCount 증가
	
}

void releaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}