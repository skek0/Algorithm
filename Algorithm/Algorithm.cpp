#include <iostream>
#include <vector>

#define SIZE 8

using namespace std;

template<typename T>
class Graph
{
private:
	bool visited[SIZE];
	vector<int> graph[SIZE];

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}
	void InsertEdge(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
		graph[edge].push_back(vertex);
	}
	void Show()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << "graph[" << i << "] : ";
			for (int j = 0; j < graph[i].size(); j++)
			{
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
#pragma region 깊이 우선 탐색 (Depth First Search)
	// 루트 노드에서 시작해서 다음 분기로 넘어가기 전에
	// 해당 분기를 완벽하게 탐색하는 방법
	// 스택 자료구조 사용

	// 1. 시작 노드를 스택에 넣고 방문처리
	// 2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면
	//	  그 노드를 스택에 넣고 방문 처리
	// 3. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드 꺼내기
	// 4. 더 이상 2번의 과정을 수행 할 수 없을 때 까지 반복

	Graph<int> graph;
	graph.InsertEdge(1, 2);
	graph.InsertEdge(1, 3);
	graph.InsertEdge(2, 4);
	graph.InsertEdge(2, 5);
	graph.InsertEdge(3, 6);
	graph.InsertEdge(3, 7);
	graph.InsertEdge(4, 5);
	graph.InsertEdge(6, 7);
	graph.Show();
#pragma endregion


	return 0;
}