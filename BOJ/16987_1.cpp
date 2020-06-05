// 계란으로 계란치기 1회차 : 90분
// https://www.acmicpc.net/problem/16987
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct EGG
{
	int s, w;
};
int N, answer;
vector <EGG> egg;

void dfs(int idx)
{
	if (idx >= N)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (egg[i].s <= 0)
				cnt += 1;
		}
		answer = max(answer, cnt);
		return;
	}

	if (egg[idx].s <= 0)
		dfs(idx + 1);
	else
	{
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			if (i == idx || egg[i].s <= 0)
				continue;

			egg[idx].s = egg[idx].s - egg[i].w;
			egg[i].s = egg[i].s - egg[idx].w;
			flag = true;
			dfs(idx + 1);
			egg[idx].s = egg[idx].s + egg[i].w;
			egg[i].s = egg[i].s + egg[idx].w;

			// cout << idx << ' ' << egg[i].s << ' ' << egg[i].w << '\n';
		}
		if (!flag)
			dfs(N);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		EGG tmp;
		cin >> tmp.s >> tmp.w;
		egg.push_back(tmp);
	}
	dfs(0);
	cout << answer << '\n';
}