#pragma once

typedef struct _tabArr {
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;


// 단축키 Ctrl + '+' + '.'
// 배열 초기화 함수
void initArr(tArr* _pArr);

// 데이터 추가 함수
void pushBack(tArr* _pArr, int _iData);

// 공간 추가 확장 함수
// main 함수에서 직접 호출 불가능하도록 헤더 파일에 명시하지 않음
//void reAlloc(tArr* _pArr);

// 배열 메모리 해제 함수
void releaseArr(tArr* _pArr);