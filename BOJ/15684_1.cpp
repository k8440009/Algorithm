// 사다리 조작
// https://www.acmicpc.net/problem/15684
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H, answer = 987654321;

int board[31][11];

void print_board()
{
	cout << '\n';
	for (int r = 1; r <= H; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			cout << board[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int check()
{
	for (int c = 1; c <= N; c++)
	{
		int pos = c;

		for (int r = 1; r <= H; r++)
		{
			if (board[r][pos] == 1)
				pos++;
			else if (board[r][pos - 1] == 1)
				pos--;
		}

		if (pos != c)
			return 0;
	}
	return 1;
}

void dfs(int s_r, int s_c, int cnt)
{
	if (cnt >= answer)
		return;
	if (check())
	{
		answer = cnt;
		return;
	}
	if (cnt == 3)
		return;

	for (int r = s_r; r <= H; r++)
	{
		for (int c = s_c; c < N; c++)
		{
			if (board[r][c] == 0 && board[r][c - 1] == 0 && board[r][c + 1] == 0)
			{
				board[r][c] = 1;
				dfs(r, c, cnt + 1);
				board[r][c] = 0;
			}
		}
		s_c = 1;
	}
}

void solve()
{
	dfs(1, 1, 0);
	if (answer == 987654321)
		answer = -1;
	cout << answer << '\n';
}
void init()
{
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int r, c;
		cin >> r >> c;
		board[r][c] = 1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();
}