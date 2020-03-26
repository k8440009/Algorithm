// 게리맨더링
// https://www.acmicpc.net/problem/17471
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 987654321;
int N;
int people[10];
int selected[10];
int visited[10];
vector<vector<int>> resion;

bool bfs(vector<int> v, int team)
{
	int node;
	queue<int> q;
	fill_n(visited, 10, 0);

	node = v[0];
	q.push(node);
	visited[node] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < resion[cur].size(); i++)
		{
			node = resion[cur][i];
			if (visited[node])
				continue;
			if (selected[node] == team)
			{
				q.push(node);
				visited[node] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (selected[i] == team)
		{
			if (!visited[i])
				return false;
		}
	}

	return true;
}
void solve()
{
	vector<int> a, b;
	for (int i = 0; i < N; i++)
	{
		if (selected[i])
			a.push_back(i);
		else
			b.push_back(i);
	}

	if (!bfs(a, 1) || !bfs(b, 0))
		return;
	int a_people = 0, b_people = 0, node;
	for (int i = 0; i < a.size(); i++)
	{
		node = a[i];
		a_people += people[node];
	}
	for (int i = 0; i < b.size(); i++)
	{
		node = b[i];
		b_people += people[node];
	}
	int total = abs(a_people - b_people);
	if (answer > total)
		answer = total;
}
void dfs(int curr, int cnt, int prev, int mx)
{
	if (cnt == mx)
	{
		solve();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (selected[i])
			continue;
		else if (prev > i)
			continue;

		selected[i] = 1;
		dfs(curr + 1, cnt + 1, i, mx);
		selected[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> people[i];
	int size;
	// 연결 정보
	for (int i = 0; i < N; i++)
	{
		cin >> size;
		vector<int> v;
		int cnt = 0;
		for (int j = 0; j < size; j++)
		{
			cin >> cnt;
			cnt--;
			v.push_back(cnt);
		}
		resion.push_back(v);
	}
	for (int i = 1; i < N; i++)
		dfs(0, 0, 0, i);
	if (answer == 987654321)
		answer = -1;
	cout << answer << '\n';
}