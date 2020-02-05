// N M (2) - 조합
// https://www.acmicpc.net/problem/15650
#include <bits/stdc++.h>
using namespace std;
const int MAX = 9;
int N, M;
vector<int> a;
bool visited[MAX];
int temp = 0;
void dfs(int index, int past)
{
	// 1. index가 M이 되었을 경우 출력
	if (index == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// 2. m의 크기가 만족하지 않는 경우
	for (int i = 1; i <= N; i++)
	{
		if (visited[i])
			continue;
		if (past > i)
			continue;

		a.push_back(i);
		visited[i] = true;
		dfs(index + 1, i);
		a.pop_back();
		visited[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	dfs(0, 0);

	return 0;
}