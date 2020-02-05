// N과 M (4) - 중복 조합
// https://www.acmicpc.net/problem/15652
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> a;
void rec(int index, int last)
{
	if (index == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (last > i)
			continue;

		a.push_back(i);
		rec(index + 1, i);
		a.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	rec(0, 0);

	return 0;
}
