#include <stdio.h>
#include <stdlib.h>

struct node {
	int v; // vertex 번호
	struct node* next;
};

struct node* graph[4]; // 배열 안에 포인터가 들어간다, init with NULL

void addEdge(int v1, int v2);
void showAdjacentVertex(int v);

int main(void)
{
	// undirected graph
	addEdge(0, 1); // 0->1, 1->0
	addEdge(1, 0);
	addEdge(0, 2); // 0->2, 2->0
	addEdge(2, 0);

	// vertex v1의 adjacent vertex는 누구?
	showAdjacentVertex(0); // 1, 2

	return 0;
}

void addEdge(int v1, int v2)
{
	struct node* neww = (struct node*)malloc(sizeof(struct node));
	struct node* cur = graph[v1];

	neww->v = v2;
	neww->next = 0;

	if (cur == 0) // v1에 아무것도 붙어있지 않는 경우
	{
		graph[v1] = neww;
		return;
	}
	else // v1에 vertex가 붙어있는 경우
	{
		while (cur->next != 0)
		{
			cur = cur->next;
		}
		
		cur->next = neww;
	}
}

void showAdjacentVertex(int v)
{
	struct node* cur = graph[v];

	while (cur != 0)
	{
		printf("%d is the adjacent vertex\n", cur->v);
		cur = cur->next;
	}
}