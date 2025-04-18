﻿#include <iostream>
#define SIZE 6
#define INFINITY 10000000

using namespace std;
class Graph
{
private:
	int weight[SIZE][SIZE] =
	{
		{0,	2, 5, 1, INFINITY, INFINITY},
		{2, 0, 3, 2, INFINITY, INFINITY},
		{5, 3, 0, 3, 1, 5},
		{1, 2, 3, 0, 1, INFINITY},
		{INFINITY, INFINITY, 1, 1, 0, 2},
		{INFINITY, INFINITY, 5, INFINITY, 2, 0}
	};
	int distance[SIZE];
	bool visited[SIZE];
public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			distance[i] = 0;
			visited[i] = false;
		}
	}

	void Dijkstra(int start)
	{
		for (int i = 0; i < SIZE; i++)
		{
			distance[i] = weight[start][i];
		}
		visited[start] = true;

		for (int i = 0; i < SIZE; i++)
		{
			int inserted = Find();
			visited[inserted] = true;

			for (int j = 0; j < SIZE; j++)
			{
				if (!visited[j] && distance[j] > distance[inserted] + weight[inserted][j])
				{
					distance[j] = distance[inserted] + weight[inserted][j];
				}
			}
		}
	}
	int Find()
	{
		int minimum = INFINITY;
		int minimumIndex = 0;
		for (int i = 0; i < SIZE; i++)
		{
			if (minimum > distance[i] && !visited[i])
			{
				minimum = distance[i];
				minimumIndex = i;
			}
		}
		return minimumIndex;
	}
	void Print()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << distance[i] << " ";
		}
	}
};

int main()
{
#pragma region 다익스트라 알고리즘
	// 시작점으로 부터 모든 노드까지의 최소 거리를 구해주는 알고리즘

	// 1. distance 배열에 weight[시작점 노드]의 값들로
	//	  초기화
	// 2. 시작점을 방문 처리
	// 3. distance 배열에서 최소 비용 노드를 찾고 방문 처리
	//    단, 이미 방문한 노드는 제외
	// 4. 최소 비용 노드를 가져갈 지 고민해서 distance 배열을 갱신
	//	  단, 이미 방문한 노드는 제외
	// 5. 모든 노드를 방문할 때 까지 3~4를 반복
	// 방문하지 않은 노드 중에서 가장 작은 distance를 가진 노드를 방문하고,
	// 그 노드와 연결된 다른 노드까지의 거리를 계산

	Graph graph;

	graph.Dijkstra(0);
	graph.Print();
#pragma endregion


	return 0;
}