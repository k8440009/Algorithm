// 네트워크 연결
// https://www.acmicpc.net/problem/1922
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000 + 1;
int N, M;
vector<pair<int, int>> graph[MAX];
struct DisjointSet
{
	vector<int> parent;

	DisjointSet(int n) : parent(n + 1)
	{
		for (int i = 1; i <= N; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v)
			return;
		if (u < v)
			swap(u, v);
		parent[u] = v;
	}
};
int kruskal()
{
	int result = 0;
	vector<pair<int, pair<int, int>>> edges;
	for (int u = 1; u <= N; u++)
	{
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i].first, cost = graph[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}

	sort(edges.begin(), edges.end());

	DisjointSet sets(N);

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;

		if (sets.find(u) == sets.find(v))
			continue;
		sets.merge(u, v);
		result += cost;
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	cout << kruskal() << '\n';
	return 0;
}
