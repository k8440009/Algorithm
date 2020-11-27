// 트리
// https://www.acmicpc.net/problem/4256
#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> pre, in;

void dfs(int root, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		if (in[i] == pre[root])
		{
			dfs(root + 1, start, i);
			dfs(root + i + (1 - start) , i + 1, end);
			cout << pre[root] << ' ';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		cin >> N;
		pre.resize(N), in.resize(N);
		for (int i = 0; i < N; i++)
			cin >> pre[i];
		for (int i = 0; i < N; i++)
			cin >> in[i];
		
		dfs(0, 0, N);
	
		pre.clear(), in.clear();
		cout << '\n';
	}
}