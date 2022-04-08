#include <stdio.h>
#include <stdlib.h>

/* 집합과 선형 리스트의 차이점 */

// 집합 : 순서가 없다, 집합 안에 데이터가 있는지 여부만 중요
// 선형 리스트 : 데이터가 있는지 여부, 순서 정보도 중요


/* 선형리스트 Linear List */

// ADT (Abstract Data Type) : 저장방식 + Operation
// 저장방식 : 배열 or Linked List...
// Operations : 추가, 삭제, 대치, 특정 아이템이 있는지, 개수, 비어있는지, 꽉 차있는지...


/* 배열을 이용한 선형리스트의 구현 */

// 단점
// 배열은 크기가 한정되어 크기를 넉넉하게 잡을 경우 -> 공간 낭비가 발생
// 공간을 작게 설정할 경우 크기가 충분한 배열로 수시로 복사 -> 속도의 저하 발생
// 중간의 데이터를 하나 삭제할 경우 이후의 데이터들을 한 칸 앞으로 복사 -> 성능의 저하 발생


/* Review of dynamic allocation */

int main(void)
{
	// heap : a memory pool from which spaces are allocated whenever needed, and returned after use
	// malloc(size in bytes) : given byte-sizes of space is allocated. It returns a pointer to the allocated space
	// free : The pointed space is freed and added to the heap for reuse.

	// Dangling pointer : a pointer to a freed space
	int* p, * q;
	int* p = (int*)malloc(4 * sizeof(int));
	q = p;
	free(q); // p now become a dangling pointer

	// Unreferenced space : a space with no pointer
	int* a, * b;
	a = (int*)malloc(4 * sizeof(int));
	b = (int*)malloc(4 * sizeof(int));
	a = b; // 기존의 a가 가리키던 heap 메모리 영역의 사용과 해제가 불가능해진다

	return 0;
}