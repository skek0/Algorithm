#include <iostream>
#include <vector>
#include <queue>
#define SIZE 8

using namespace std;
class Graph
{
private:
	int degree[SIZE]; // 진입 차수
	queue<int>  queue;
	vector<int> graph[SIZE];
public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			degree[i] = NULL;
		}
	}

	void Insert(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
		degree[edge]++;
	}
	void Sort()
	{
		for (int i = 1; i < SIZE; i++)
		{
			if (degree[i] == 0)
			{
				queue.push(i);
			}
		}

		while (!queue.empty())
		{
			int front = queue.front();

			queue.pop();

			cout << front << " ";

			for (int i = 0; i < graph[front].size(); i++)
			{
				int start = graph[front][i];
				degree[start]--;
				if (degree[start] == 0)
				{
					queue.push(start);
				}
			}
		}
	}
};

int main()
{
#pragma region 위상 정렬
	// 방향 그래프에 존재하는 각 정점들의 선행 순서를 지키며,
	// 모든 정점을 차례대로 진행하는 알고리즘

	// 사이클이 발생하는 경우, 위상 정렬을 수행할 수 없음

	// DAG(Directed Acyclic Graph) : 사이클이 존재하지 않는 그래프

	// 시간 복잡도 : O(W+E)

	// 위상 정렬 방법

	// 1. 진입 차수가 0인 정점을 Queue에 삽입
	// 2. Queue에서 원소를 꺼내 연결된 모든 간선을 제거
	// 3. 간선 제거 이후에 진입 차수가 0이 된 정점을 Queue에 삽입
	// 4. Queue가 비어있을 때까지 2~3번을 반복 수행

	Graph graph;

	graph.Insert(1, 2);
	graph.Insert(1, 5);
	graph.Insert(2, 3);
	graph.Insert(3, 4);
	graph.Insert(4, 6);
	graph.Insert(5, 6);
	graph.Insert(6, 7);

	graph.Sort();

#pragma endregion

	return 0;
}