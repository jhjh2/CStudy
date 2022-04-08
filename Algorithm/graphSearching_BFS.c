/* Graph Searching 탐색 */
// 하나의 vertex에서 시작하여 graph의 모든 vertex를 방문하는 알고리즘
// - 그래프의 모든 연결된 vertex를 중복 없이 방문
// 두 가지 알고리즘 : Depth First Search (DFS), Breadth First Search (BFS)

// Breadth First Search
// 연결되어 있는 모든 vertex들을 먼저 방문
// 큐를 이용하여 구현

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_VERTEX 5

struct node {
	int v; // vertex 번호
	struct node* next;
};

struct node* graph[NUMBER_OF_VERTEX]; // 배열 안에 노드 포인터가 들어간다, init with NULL

/*----- vertex 방문여부 표시 배열 -----*/
// if visited[i] == 1, visited
//                  0, otherwise
int visited[NUMBER_OF_VERTEX] = { 0 };

/*----- 큐 관련 -----*/
int head = 0;
int tail = 0;
int queue[NUMBER_OF_VERTEX];

void enqueue(int v)
{
	if ((tail + 1) % NUMBER_OF_VERTEX == head)
	{
		printf("the queue is full\n");
		return;
	}
	queue[tail] = v;
	tail = (tail + 1) % NUMBER_OF_VERTEX;
}

int isQueueEmpty()
{
	return head == tail ? 1 : 0;
}

// return -999 if the queue is empty
int dequeue()
{
	int temp = -999;
	if (isQueueEmpty() == 0)
	{
		temp = queue[head];
		head = (head + 1) % NUMBER_OF_VERTEX;
		return temp;
	}

	return temp;
}

void addAdjacentNonVisitedVertexToQueue(int v)
{
	struct node* cur = graph[v];

	while (cur != 0)
	{
		if (visited[cur->v] == 0)
		{
			enqueue(cur->v);
		}
		cur = cur->next;
	}
}

void doBFS(int v)
{
	enqueue(v);

	while (isQueueEmpty() == 0)
	{
		int k = dequeue();

		if (visited[k] == 0)
		{
			printf("BFS visited %d \n", k);
			visited[k] = 1;

			addAdjacentNonVisitedVertexToQueue(k);
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
	doBFS(0);

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