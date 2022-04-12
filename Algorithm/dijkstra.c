/* Dijkstra 알고리즘 */
// 하나의 vertex로부터 시작
// 최단 거리의 vertex를 하나씩 추가
// 모든 vertex에 대한 최단 거리를 찾을 때까지 반복

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_VERTEX 5
#define NUMBER_OF_EDGES 8

struct node {
	int v; // vertex 번호
	int weight;
	struct node* next;
};

struct edge {
	int from;
	int to;
	int weight;
};

struct dijkstra {
	int found; // K, 최단거리가 알려졌는가? 1 == YES, 0 == NO
	int distance;
	int prev_vertex;
};

struct dijkstra dtable[NUMBER_OF_VERTEX];

struct edge edges[NUMBER_OF_EDGES];

struct node* graph[NUMBER_OF_VERTEX]; // 배열 안에 포인터가 들어간다, init with NULL

void addEdge(int v1, int v2, int weight, int doReverse);
void showAdjacentVertex(int v);

void initDTable()
{
	int i;
	for (i = 0; i < NUMBER_OF_VERTEX; i++)
	{
		dtable[i].found = 0;
		dtable[i].distance = 99999;
		dtable[i].prev_vertex = -1;
	}
}

// 최단거리가 알려지지 않은 vertex 중에서,
// distance가 가장 짧은 vertex를 반환
// return -1 if 모든 vertex의 최단거리가 알려졌을 경우
int findDijkstraNextVertex()
{
	int i;
	int smallest_distance = 99999;
	int smallest_vertex = -1;

	for (i = 0; i < NUMBER_OF_VERTEX; i++)
	{
		if (dtable[i].found == 0 && dtable[i].distance < smallest_distance)
		{
			smallest_vertex = i;
			smallest_distance = dtable[i].distance;
		}
	}

	return smallest_vertex;
}

void showDTable()
{
	int i;
	for (i = 0; i < NUMBER_OF_VERTEX; i++)
	{
		printf("%d : %d %d %d \n", i, dtable[i].found, dtable[i].distance, dtable[i].prev_vertex);
	}
}

void updateDTable(int v)
{
	struct node* cur = graph[v];

	while (cur != 0)
	{
		// 최단거리가 알려지지 않았고,
		// 기존에 알려진 거리보다, v를 통할 경우 더 가까우면 dtable을 update한다
		if (dtable[cur->v].found == 0 && (dtable[cur->v].distance > dtable[v].distance + cur->weight))
		{
			dtable[cur->v].distance = dtable[v].distance + cur->weight;
			dtable[cur->v].prev_vertex = v;
		}

		cur = cur->next;
	}
}

void doDijkstra(int v)
{
	int next_vertex = -1;
	dtable[v].distance = 0;

	while ((next_vertex = findDijkstraNextVertex()) != -1)
	{
		dtable[next_vertex].found = 1; // 최단거리를 찾았다고 표시
		updateDTable(next_vertex);
	}

	showDTable();
}

int main(void)
{
	// undirected graph
	addEdge(0, 1, 1, 0);
	addEdge(0, 2, 3, 0);
	addEdge(0, 4, 5, 0);
	addEdge(1, 2, 2, 0);
	addEdge(1, 4, 4, 0);
	addEdge(2, 4, 6, 0);
	addEdge(2, 3, 7, 0);
	addEdge(3, 4, 8, 0);

	initDTable();

	doDijkstra(0);

	return 0;
}

// if deReverse == 1, 1->0
// otherwise
void addEdge(int v1, int v2, int weight, int doReverse) // 0
{
	struct node* neww = (struct node*)malloc(sizeof(struct node));
	struct node* cur = graph[v1];

	neww->v = v2;
	neww->next = 0;
	neww->weight = weight;

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
		addEdge(v2, v1, weight, 0);
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