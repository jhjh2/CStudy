/* Graph Searching 탐색 */
// 하나의 vertex에서 시작하여 graph의 모든 vertex를 방문하는 알고리즘
// - 그래프의 모든 연결된 vertex를 중복 없이 방문
// 두 가지 알고리즘 : Depth First Search (DFS), Breadth First Search (BFS)

// Depth First Search
// 막다른 길에 다다르면 갈림길이 있던 곳으로 돌아와서 다시 시작
// 스택을 이용하여 구현

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_VERTEX 5

struct node {
	int v; // vertex 번호
	struct node* next;
};

struct node* graph[NUMBER_OF_VERTEX]; // 배열 안에 포인터가 들어간다, init with NULL

/*----- vertex 방문여부 표시 배열 -----*/
// if visited[i] == 1, visited
//                  0, otherwise
int visited[NUMBER_OF_VERTEX] = { 0 };

/*----- 스택 관련 -----*/
int stack[NUMBER_OF_VERTEX];
int top = -1;
void push(int v)
{
	if (top == NUMBER_OF_VERTEX - 1)
	{
		printf("stack is full\n");
		return;
	}
	top++;
	stack[top] = v;
}

// return 1 if the stack is empty
//        0 otherwise
int isStackEmpty()
{
	return top == -1 ? 1 : 0;
}

int pop()
{
	if (top == -1)
	{
		printf("stack is empty\n");
		return -999;
	}
	int temp = stack[top];
	top--;

	return temp;
}

// v와 연결된 vertex 중 아직까지 방문하지 않은 vertex를 반환
// 만약, 조건을 만족하는 vertex가 없는 경우 -1을 반환
int findNextVertex(int v)
{
	struct node* cur = graph[v];

	while (cur != 0)
	{
		if (visited[cur->v] == 0)
		{
			return cur->v;
		}
		cur = cur->next;
	}

	return -1; // v에 연결된 vertex 중 방문하지 않은 것이 없다
}

void doDFS(int v)
{
	printf("visited %d \n", v);
	visited[v] = 1;
	push(v);

	while (isStackEmpty() == 0)
	{
		int nextVertex = -1;
		nextVertex = findNextVertex(stack[top]);

		if (nextVertex == -1)
		{
			pop();
		}
		else
		{
			printf("visited %d \n", nextVertex);
			visited[nextVertex] = 1;
			push(nextVertex);
		}
	}
}

void addEdge(int v1, int v2, int doReverse);
void showAdjacentVertex(int v);

int main(void)
{
	// undirected graph
	addEdge(0, 1, 1); // 0->1, 1->0
	addEdge(0, 2, 1);
	addEdge(0, 4, 1); 
	addEdge(1, 2, 1);
	addEdge(2, 3, 1);
	addEdge(2, 4, 1);
	addEdge(3, 4, 1);

	// vertex 0에서 시작하여 DFS를 실행
	doDFS(0);

	return 0;
}

// if deReverse == 1, 1->0
// otherwise
void addEdge(int v1, int v2, int doReverse) // 0
{
	struct node* neww = (struct node*)malloc(sizeof(struct node));
	struct node* cur = graph[v1];

	neww->v = v2;
	neww->next = 0;

	if (cur == 0) // v1에 아무것도 붙어있지 않는 경우
	{
		graph[v1] = neww;
		
	}
	else // v1에 vertex가 붙어있는 경우
	{
		while (cur->next != 0)
		{
			cur = cur->next;
		}

		cur->next = neww;
	}

	if (doReverse == 1)
	{
		addEdge(v2, v1, 0);
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