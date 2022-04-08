#include <stdio.h>
#include <stdlib.h>

/* Singly Linked List */

// (head)□→□→□→□→□→NULL
// □ = node, → = link

// add, delete, destroy 과정

// C inplementation of a singly linked list
struct node { // 자기참조 구조체 Self referential structure
	int data;
	struct node* next; // link
};

struct node* head = 0;

void addToSLL(int v);
void printSLL();
void destroySLL();
void insertToSLL(int data, int v);
void deleteFromSLL(int data);

int main(void)
{

	// Node creation and deletion
	struct node* p;
	p = (struct node*)malloc(sizeof(struct node));
	p->data = 10;
	printf("%d \n", p->data);
	free(p);

	// SLL: add
	addToSLL(1);
	addToSLL(2);
	addToSLL(3);

	printSLL(); // 1, 2, 3

	// SLL: destroy
	destroySLL();

	addToSLL(4);
	addToSLL(5);
	addToSLL(6);

	printSLL(); // 4, 5, 6

	// SLL: insert
	insertToSLL(4, 10);
	insertToSLL(10, 100);
	insertToSLL(90, 7);

	printSLL(); // 4, 10, 100, 5, 6

	// SLL: delete
	deleteFromSLL(10);

	printSLL(); // 4, 100, 5, 6

	return 0;
}

void addToSLL(int v)
{
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->data = v;
	newn->next = 0;

	// SLL의 마지막에 node 추가
	if (head == 0)
	{
		// SLL에 아무것도 없는 경우
		head = newn;
		return;
	}
	else
	{
		// SLL에 이미 무언가가 있는 경우
		struct node* last = 0;
		last = head;

		while (last->next != 0)
		{
			last = last->next;
		}

		last->next = newn;
		return;
	}
}

void printSLL()
{
	struct node* cur = head;

	while (cur != 0)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	return;
}

void destroySLL()
{
	struct node* cur = head;

	while (head != 0)
	{
		head = head->next;
		free(cur);

		cur = head;
	}
}

void insertToSLL(int data, int v)
{
	struct node* cur = head;

	while (cur != 0) // 비어있는 SLL이거나 해당하는 data가 없는 경우 삽입 않고 종료
	{
		if (cur->data == data)
		{
			// 노드를 삽입할 위치 찾기
			struct node* newn = (struct node*)malloc(sizeof(struct node));
			newn->data = v;

			// 노드 삽입 과정
			newn->next = cur->next;
			cur->next = newn;

			return;
		}
		else
		{
			cur = cur->next;
		}
	}


}

void deleteFromSLL(int data)
{
	struct node* del; // 지울 노드를 가리키는 포인터
	struct node* del_next; // 지울 노드의 바로 앞 노드를 가리키는 포인터

	// 노드 제거 과정
	if (head->data == data) // 지울 노드가 head인 경우
	{
		del = head;
		head = head->next;
		free(del);

		return;
	}
	else // 지울 노드가 head가 아닌 경우
	{
		del_next = head;
		while (del_next->next != 0)
		{
			if (del_next->next->data == data)
			{
				del = del_next->next;
				del_next->next = del->next;
				free(del);

				return;
			}
			else
			{
				del_next = del_next->next;
			}
		}
	}
}