// 줄 세우기
// https://www.acmicpc.net/problem/2252
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 32000 + 1;
int N, M, indegree[MAX], result[MAX];
vector<int> adj[MAX];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int prev, curr;
		cin >> prev >> curr;
		indegree[curr - 1]++;
		adj[prev - 1].push_back(curr - 1);
	}

	queue<int> q;
	// 위상정렬 시작 : 큐에 indegree 0인 정점을 다 넣는다.
	for (int i = 0; i < N; i++)
		if (indegree[i] == 0)
			q.push(i);

	// 위상 정렬
	for (int i = 0; i < N; i++)
	{
		// 도중에 큐가 비어버리면 불가능
		if (q.empty())
		{
			cout << 0 << '\n';
			return 0;
		}

		int curr = q.front();
		q.pop();
		result[i] = curr + 1;
		// 인접한 정점을 순회하면서 indegree 1씩 감소, 0이되면 큐에 넣는다.
		for (int next : adj[curr])
			if (--indegree[next] == 0)
				q.push(next);
	}

	for (int i = 0; i < N; i++)
		cout << result[i] << ' ';
	cout << '\n';
	return 0;
}