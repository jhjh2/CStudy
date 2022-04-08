#include <stdio.h>
#include <stdlib.h>

/* Doubly Linked List */

// C inplementation of a doubly linked list
struct node {
	int data;
	struct node* prev;
	struct node* next;
};

struct node* head = 0;

void addToDLL(int k);
void printDLL();
void insertToDLL(int data, int k);
void delFromDLL(int data);

int main(void)
{
	// Node creation and deletion
	struct node* p;
	p = (struct node*)malloc(sizeof(struct node));
	free(p);

	// DLL: add
	addToDLL(1);
	addToDLL(2);
	addToDLL(3);
	addToDLL(4);

	printDLL(); // 1, 2, 3, 4

	// DLL: insert
	insertToDLL(3, 50);
	insertToDLL(3, 10);
	insertToDLL(51, 100);

	printDLL(); // 1, 2, 3, 10, 50, 4

	// DLL: delete
	delFromDLL(50);
	delFromDLL(8);
	delFromDLL(4);

	printDLL(); // 1, 2, 3, 10

	return 0;
}

void addToDLL(int k)
{
	struct node* neww = (struct node*)malloc(sizeof(struct node));
	neww->data = k;
	neww->prev = 0;
	neww->next = 0;

	if (head == 0) // DLL에 노드가 없는 경우
	{
		head = neww;

		return;
	}
	else
	{
		struct node* cur = head;

		while (cur->next != 0)
		{
			cur = cur->next;
		}

		cur->next = neww;
		neww->prev = cur;

		return;
	}
}

void printDLL()
{
	struct node* cur = head;

	while (cur != 0)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

void insertToDLL(int data, int k)
{
	struct node* cur = head;
	struct node* neww = 0;

	// 1. 노드를 삽입할 위치 찾기
	while (1)
	{
		if (cur == 0)
		{
			return; // DLL에 노드가 없거나 찾는 값이 없는 경우 insertToDLL() 종료
		}

		if (cur->data != data)
		{
			cur = cur->next;
		}
		else
		{
			break;
		}
	}

	// 2. 노드 삽입 과정
	neww = (struct node*)malloc(sizeof(struct node));
	neww->data = k;
	neww->next = neww->prev = 0;

	neww->next = cur->next;
	neww->prev = cur;

	cur->next = neww;
	if (neww->next != 0) // DLL의 중간에 삽입하는 경우에만 실행
	{
		neww->next->prev = neww; // 맨 끝 노드의 뒤에 삽입하는 경우 에러 발생
	}
}

void delFromDLL(int data)
{
	struct node* cur = head;

	// 1. 지울 노드 위치 찾기
	while (1)
	{
		if (cur == 0)
		{
			return; // DLL에 노드가 없거나 찾는 값이 없는 경우 delFromDLL() 종료
		}

		if (cur->data != data)
		{
			cur = cur->next;
		}
		else
		{
			break;
		}
	}

	// 2. 노드 삭제 과정 (4 가지 경우의 수)
	if (cur == head) // 삭제할 노드가 head인 경우 head 포인터를 먼저 옮겨야 한다
	{
		head = head->next;
		if (head != 0) // 삭제할 노드가 마지막 노드가 아닌 경우 실행
		{
			head->prev = 0; // 삭제할 노드 다음이 NULL인 경우 오류 발생
		}
		free(cur);
	}
	else // 삭제할 노드가 head가 아닌 경우
	{
		cur->prev->next = cur->next;
		if (cur->next != 0) // 삭제할 노드가 마지막 노드가 아닌 경우 실행
		{
			cur->next->prev = cur->prev; // 삭제할 노드 다음이 NULL인 경우 오류 발생
		}
		free(cur);
	}
}