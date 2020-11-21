// 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
using namespace std;

int N;
vector <vector <int> > tree;
int parent[100000 + 1];

void dfs(int node)
{

	for (auto vertex : tree[node])
	{
		//if (node != 1 && parent[node] == vertex)
		if (parent[node] == vertex)
			continue;
		parent[vertex] = node;
		dfs(vertex);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N;
	tree.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}