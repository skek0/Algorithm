#include <iostream>
#include <vector>
#include <queue>
#define SIZE 8

using namespace std;

class Graph
{
private:
	bool visited[SIZE];
	vector<int> graph[SIZE];
	queue<int> queue;
public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}
	void Insert(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
		graph[edge].push_back(vertex);
	}
	void WFS(int start)
	{
		queue.push(start);
		cout << start << " ";
		visited[start] = true;
		for (int i = 0; i < graph[start].size(); i++)
		{
			if (!visited[graph[start][i]])
			{
				WFS(graph[start][i]);
			}
		}
		queue.pop();
	}
};

int main()
{
#pragma region 너비 우선 탐색
	// 시작 정점을 방문한 후 시작 정점에 인접한 
	// 모든 정점을 우선 방문하는 방법

	// 더 이상 방문하지 않은 정점이 없을 때까지
	// 방문하지 않은 모든 정점들에 대해서도 너비 우선 탐색을 적용

	Graph graph;

	graph.Insert(1, 2);
	graph.Insert(1, 3);
	graph.Insert(2, 4);
	graph.Insert(2, 5);
	graph.Insert(3, 6);
	graph.Insert(3, 7);

	graph.WFS(1);

#pragma endregion

	return 0;
}