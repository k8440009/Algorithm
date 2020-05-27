// 사다리 조작 2회차 : 180분
// https://www.acmicpc.net/problem/15684
#include <iostream>
using namespace std;

int N, M, H, answer = 4;
int board[32][11];

void solve(int cnt)
{
	for (int s_c = 1; s_c <= N; s_c++)
	{
		int r = 1, c = s_c;
		while (r <= H)
		{
			if (board[r][c] == 1)
				c += 1;
			else if (board[r][c - 1] == 1)
				c -= 1;
			r++;
		}
		if (c != s_c)
			return;
	}
	answer = cnt;
	return;
}

void dfs(int cnt, int s_r, int s_c)
{
	if (cnt <= 3)
		solve(cnt);

	if (cnt == 3 || cnt > answer)
		return;

	for (int r = s_r; r <= H; r++)
	{
		for (int c = s_c; c <= N - 1; c++)
		{
			if (board[r][c] == 1 || board[r][c - 1] == 1)
				continue;
			board[r][c] = 1;
			dfs(cnt + 1, r, c);
			board[r][c] = 0;

		}
		s_c = 1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int r, c;
		cin >> r >> c;
		board[r][c] = 1;
	}
	solve(0);
	if (answer != 0)
 	{
		dfs(0, 1, 1);
		if (answer == 4)
			answer = -1;
	}
	cout << answer << '\n';
}