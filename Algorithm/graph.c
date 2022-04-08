/* 그래프 Graph */
// 용어
// 정점 Vertex, Node : ○
// 간선 Edge : - or →

// Edge의 방향성 유무에 따라
// directed graph : ⓑ←ⓐ→ⓒ
// undirected graph : ⓑ-ⓐ-ⓒ

// 가중치 weighted graph
// 가중치 : Edge 위에 부여된 값

// Adjacent Vertex 인접한 정점
// 한 정점과 Edge로 연결된 정점들
// ⓑ-ⓐ-ⓒ
// a's adjacent vertex : b, c
// c's adjacent vertex : a

// Degree
// 한 정점과 연결된 Edge의 개수
// undirected graph ⓑ-ⓐ-ⓒ
// a's degree : 2
// c's degree : 1
// directed graph ⓑ←ⓐ←ⓒ
// a's in-degree : 1
// a's out-degree : 1
// b's in-degree : 1
// c's out-degree : 1

// cycle
// 출발과 도착이 같은

// complete graph
// 한 정점이 그래프의 모든 정점들과 연결된 그래프
// vertex가 n개인 경우
// # of edge = n * (n-1) / 2


/* 그래프의 구현 */ 
// 2차원 배열을 사용하여 구현
// undirected graph인 경우 배열이 비대칭
// Edge가 적은 그래프를 2차원 배열로 나타낼 경우 공간 낭비

// SLL를 사용하여 구현
// Edge가 적은 그래프를 표현하는 경우 효율적
// Edge가 많은 그래프를 표현하는 경우 공간을 많이 차지

// dense graph : Edge의 개수가 많은 그래프 -> 2차원 배열로 구현 (일반적으로)
// sparse graph : Edge의 개수가 적은 그래프 -> SLL로 구현 (일반적으로)

#include <stdio.h>

int graph[4][4]; // init with zero

void addEdge(int v1, int v2);
void showAdjacentVertex(int v);

int main(void)
{
	// undirected graph
	addEdge(0, 1); // 0->1, 1->0
	addEdge(0, 2); // 0->2, 2->0

	// vertex v1의 adjacent vertex는 누구?
	showAdjacentVertex(0); // 1, 2

	return 0;
}

void addEdge(int v1, int v2)
{
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
}

void showAdjacentVertex(int v)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (graph[v][i] == 1)
		{
			printf("%d is the adjacent vertex\n", i);
		}
	}
}