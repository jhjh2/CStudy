/* 우선순위 큐 Priority queue */

// 큐에 우선순위의 개념을 도입
// 보통의 큐는 First in First out 원칙으로 동작
// 우선순위 큐는 데이터들이 우선순위 priority를 가지고 있음
// 우선순위가 높은 데이터가 먼저 out


/* 우선순위 큐 vs Stack & Queue */

// 스택 데이터는 우선순위가 없음
// 스택은 Last in First out 원칙
// 큐는 First in First out

/* 우선순위 큐의 이해 */
// 우선순위 큐는 가장 일반적인 큐
// 스택과 큐도 일종의 우선순위 큐
// 주로 시뮬레이션에서 사용 : 사건이 시간 순으로 발생하도록
// 구현 방법 : 배열, SLL, Heap


/* 우선순위 큐 구현을 위한 배열과 SLL */

// 배열을 이용한 우선순위 큐 구현
// 1. 정렬이 안 된 배열을 사용
// 삽입 : 맨 끝에 삽입, O(1)
// 삭제 : 가장 우선순위가 높은 것을 탐색하여 삭제, O(n)
//
// 2. 정렬이 되어 있는 배열을 사용
// 삽입 : 기존 값들과 비교하여 위치를 탐색함, O(n)
// 삭제 : 우선순위에 따라 정렬되어 있음, O(1)

// SLL을 이용한 우선순위 큐 구현
// 1. 정렬이 안 된 SLL을 사용
// 삽입 : 맨 앞에 삽입, O(1)
// 삭제 : 가장 우선순위가 높은 것을 탐색하여 삭제, O(n)
//
// 2. 정렬이 된 SLL을 사용
// 삽입 : 기존 값들과 비교하여 위치를 탐색함, O(n)
// 삭제 : 맨 앞의 노드를 삭제, O(1)


/* Heap을 이용한 우선순위 큐 구현 */

// Heap의 조건 2가지
// 1. 잘 생겨야 한다 : 가장 낮은 level의 오른쪽 노드부터 비어있어야 한다
// 2. Max Heap, Min Heap
// Max Heap : 부모 값 > 자식 값
// Min Heap : 부모 값 <= 자식 값

// Heap과 우선순위 큐의 관계
// root 노드의 우선순위가 가장 높음

// Max Heap의 구현: 배열
// index 0번은 의도적으로 비워둔다
// 자식노드의 인덱스는 부모 노드의 index * 2와 (index * 2) + 1이다

// Heap 정렬, 삽입, 삭제
// 정렬 Heapify : 자식을 가진 마지막 노드에서부터 역순으로 올라오며 정렬 후 recursive하게 내려오며 다시 정렬
// 삽입 : 새로운 노드를 맨 마지막 index에 저장한 후 heapify
// 삭제 : root 노드의 값만 삭제 가능, 삭제 마지막 노드를 root 자리로 옮긴 다음 위에서부터 정렬

#include <stdio.h>

// Max Heap
int data[20] = { 0, 6, 3, 5, 7, 10, 1, 2 };

void swap(int i, int j);
void findLocation(int curIndex, int lastIndex);
void heapify(int lastIndex);
void addToHeap(int value, int lastIndex);
int removeRoot(int lastIndex);

int main(void)
{
	printf("Before heapify : %d \n", data[1]); // 6

	heapify(7); // 마지막 노드의 index 값을 넘겨준다

	printf("After heapify : %d \n", data[1]); // 10

	addToHeap(30, 7);

	printf("After adding : %d \n", data[1]); // 30

	addToHeap(40, 8);

	printf("After adding : %d \n", data[1]); // 40

	addToHeap(20, 9);

	printf("After adding : %d \n", data[1]); // 40

	int k;
	k = removeRoot(10);

	printf("After removing %d, root is %d \n", k, data[1]); // 40, 30

	return 0;
}

// data[i] <--> data[j]
void swap(int i, int j)
{
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void findLocation(int curIndex, int lastIndex)
{
	// 왼쪽 자식과 오른쪽 자식 노드의 index를 계산한다
	int leftIndex = curIndex * 2;
	int rightIndex = leftIndex + 1;

	// 부모 노드, 왼쪽 자식 노드, 오른쪽 자식 노드 중에서 어느쪽이 더 큰 값을 갖는지 판단한다
	int biggest = curIndex; // 가장 큰 값을 가진 노드의 index를 저장

	if (leftIndex <= lastIndex && data[leftIndex] > data[curIndex])
	{
		biggest = leftIndex;
	}

	if (rightIndex <= lastIndex && data[rightIndex] > data[biggest])
	{
		biggest = rightIndex;
	}

	// 가장 큰 값을 부모노드에 저장한다
	if (biggest == curIndex)
	{
		return;
	}
	else
	{
		swap(curIndex, biggest); // index의 데이터 값만 교환, index가 가리키는 노드는 그대로이다
		findLocation(biggest, lastIndex); // recursive call, 아래로 내려간 값에 대해 내려가며 정렬
	}
}

void heapify(int lastIndex)
{
	int curIndex = lastIndex / 2;

	while (curIndex >= 1)
	{
		// curIndex가 가리키는 노드가 max heap에서 제자리를 찾도록 재배열
		findLocation(curIndex, lastIndex);
		curIndex--;
	}
}

void addToHeap(int value, int lastIndex)
{
	int curIndex = lastIndex + 1;
	data[curIndex] = value;

	int parentIndex = curIndex / 2;
	while (1)
	{
		if (data[parentIndex] > data[curIndex])
		{
			return;
		}
		else
		{
			swap(parentIndex, curIndex);
			curIndex = parentIndex;
			parentIndex = parentIndex / 2;

			if (parentIndex < 1)
			{
				return;
			}
		}
	}
}

int removeRoot(int lastIndex)
{
	int retValue = data[1];

	data[1] = data[lastIndex];
	findLocation(1, lastIndex - 1);

	return retValue;
}