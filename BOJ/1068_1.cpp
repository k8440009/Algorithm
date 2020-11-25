// 트리
// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 50 + 1;

int N, M;
int parent[MAX];
vector<int> adj[MAX];
vector <int> roots;
int answer;

void dfs(int idx)
{
	int cnt = 0;
	for (int data : adj[idx])
	{
		if (data == M)
			continue;
		cnt++;
		if (cnt > 1)
			break;
	}

	if (cnt == 1)
	{
		answer++;
		return;
	}

	for (int data : adj[idx])
	{
		if (data == -1 || parent[idx] == data || data == M)
			continue;
		dfs(data);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	fill_n(parent, MAX, -1);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == -1)
			roots.push_back(i);
		parent[i] = tmp;
		adj[i].push_back(tmp);
		if (tmp != -1)
			adj[tmp].push_back(i);
	}
	cin >> M;
	adj[M].clear();
	for (int root : roots)
	{
		if (M != root)
			dfs(root);
	}
	cout << answer;
}