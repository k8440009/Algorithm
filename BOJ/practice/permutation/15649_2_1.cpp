// N과 M (1) 순열, 백트래킹
// https://www.acmicpc.net/problem/15649
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
bool selected[9];
void dfs(int cnt)
{

	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (selected[i])
			continue;
		selected[i] = 1;
		v.push_back(i + 1);
		dfs(cnt + 1);
		selected[i] = 0;
		v.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	dfs(0);
}