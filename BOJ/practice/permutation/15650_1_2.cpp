// N과 M (2) 조합, 백트래킹
// https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num, v;
int selected[9];
void dfs(int curr, int prev)
{
	if (curr == M)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (selected[i])
			continue;
		else if (prev > i)
			continue;

		selected[i] = 1;
		v.push_back(i + 1);
		dfs(curr + 1, i);
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
	num.resize(N);
	for (int i = 0; i < N; i++)
		num[i] = i + 1;
	dfs(0, 0);
}