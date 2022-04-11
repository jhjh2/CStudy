/* Minimum Spanning Tree */

// 그래프의 모든 vertex를 최소 edge의 weight로 연결한 그래프
// 응용 : 최소 비용으로 모든 도시를 도로로 연결, 통신망 연결

// 가장 작은 weight를 갖는 edge를 추가하면서 모든 vertex가 연결될 때까지 반복한다.
// 단, cycle이 발생하여서는 안된다.

// Kruskal's Algorithm
// Edge만을 대상으로
// Two steps: cycle을 피하면서
//  - weight의 오름차순으로
//  - vertex -1개의 edge가 포함될 때까지 반복

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

struct edge edges[NUMBER_OF_EDGES];

struct node* graph[NUMBER_OF_VERTEX]; // 배열 안에 포인터가 들어간다, init with NULL

/*----- cycle detection array -----*/
int cycleDetection[NUMBER_OF_VERTEX] = { 0,1,2,3,4 };

/*----- cycle detection function -----*/
void putIntoSameGroup(int v1, int v2)
{
	int g1 = cycleDetection[v1];
	int g2 = cycleDetection[v2];
	int smaller, bigger;
	if (g1 > g2)
	{
		bigger = g1;
		smaller = g2;
	}
	else
	{
		bigger = g2;
		smaller = g1;
	}
	{
		int i;
		for (i = 0; i < NUMBER_OF_VERTEX; i++)
		{
			if (cycleDetection[i] == bigger)
			{
				cycleDetection[i] = smaller;
			}
		}
	}
}



void addEdge(int v1, int v2, int weight, int doReverse);
void showAdjacentVertex(int v);

void swapEdge(int e1, int e2)
{
	struct edge temp;
	temp = edges[e1];
	edges[e1] = edges[e2];
	edges[e2] = temp;
}

void sortEdges()
{
	// 모든 edge를 edges 배열에 추가
	int edges_index = 0;
	int i;
	for (i = 0; i < NUMBER_OF_VERTEX; i++)
	{
		struct node* cur = graph[i];

		while (cur != 0)
		{
			edges[edges_index].from = i;
			edges[edges_index].to = cur->v;
			edges[edges_index].weight = cur->weight;
			edges_index++;
			cur = cur->next;
		}
	}

	// 오름차순으로 정렬, by bubble sort
	{
		int x, y;

		for (y = 0; y < NUMBER_OF_EDGES; y++)
		{
			for (x = 0; x < NUMBER_OF_EDGES - 1 - y; x++)
			{
				if (edges[x].weight > edges[x + 1].weight)
				{
					swapEdge(x, x + 1);
				}
			}
		}
	}
}

void doMST()
{
	int i;
	int mstEdges = 0;
	for (i = 0; i < NUMBER_OF_EDGES; i++)
	{
		if (cycleDetection[edges[i].from] != cycleDetection[edges[i].to])
		{
			printf("MST edge %d --- %d (%d) \n", edges[i].from, edges[i].to, edges[i].weight);
			mstEdges++;
			if (mstEdges == NUMBER_OF_VERTEX - 1)
			{
				return;
			}
			putIntoSameGroup(edges[i].from, edges[i].to);
		}
	}
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

	sortEdges();

	doMST();

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