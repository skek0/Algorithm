#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 8

using namespace std;

class Graph
{
private:
	class Edge
	{
	private:
		int x;
		int y;
		int distance;

	public:
		Edge(int x, int y, int distance)
		{
			this->x = x;
			this->y = y;
			this->distance = distance;
		}

		const int& X()
		{
			return x;
		}
		const int& Y()
		{
			return y;
		}
		const int& Distance()
		{
			return distance;
		}

		const bool operator < (const Edge& edge)
		{
			return this->distance < edge.distance;
		}
	};

	vector<Edge> graph;
	int cost;
	int parent[SIZE];

public:
	Graph()
	{
		cost = 0;

		for (int i = 0; i < SIZE; i++)
		{
			parent[i] = i;
		}
	}

	void Insert(int x, int y, int distance)
	{
		graph.push_back(Edge(x, y, distance));
	}
	void Kruskal()
	{
		sort(graph.begin(), graph.end());

		for (int i = 0; i < graph.size(); i++)
		{
			if (!Same(graph[i].X(), graph[i].Y()))
			{
				cost += graph[i].Distance();

				Union(graph[i].X(), graph[i].Y());
			}
		}

		cout << "Minimum cost : " << cost << endl;
	}
	int Find(int x)
	{
		if (parent[x] != x)
		{
			return parent[x] = Find(parent[x]);
		}
		else return x;
	}
	void Union(int x, int y)
	{
		x = Find(x);
		y = Find(y);

		if (x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
	}
	bool Same(int x, int y)
	{
		if (Find(x) == Find(y)) return true;
		else return false;
	}

};

int main()
{
#pragma region 신장 트리
	// 그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는
	// 부분 그래프로, 그래프의 모든 정점을 최소 비용으로 연결하는 트리

	// 그래프의 정점의 수가 n개일 때, 간선의수는 n-1개

	// 최소 비용 신장 트리
	// 그래프의 간선들의 가중치 합이 최소인 신장 트리

	Graph graph;

	graph.Insert(1, 2, 67);
	graph.Insert(1, 4, 28);
	graph.Insert(1, 5, 17);
	graph.Insert(1, 7, 12);
	graph.Insert(2, 4, 24);
	graph.Insert(2, 5, 64);
	graph.Insert(3, 5, 20);
	graph.Insert(3, 6, 35);
	graph.Insert(4, 7, 13);
	graph.Insert(5, 6, 40);
	graph.Insert(5, 7, 73);

	graph.Kruskal();

#pragma endregion


	return 0;
}