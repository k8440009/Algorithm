// 사다리 조작
// https://www.acmicpc.net/problem/15684
#include <iostream>
using namespace std;

int N,M,H;
int board[31][11];
int answer = 4;

bool simulate(int cnt)
{
	for (int s_c = 0; s_c < N; s_c++)
	{
		int r = 0, c = s_c;
		while (r < H)
		{
			if (board[r][c] == 1)
				c += 1;
			else if (c - 1 >= 0 && board[r][c - 1] == 1)
				c -= 1;
			r++;
		}
		if (c != s_c)
			return false;
	}
	return true;
}

void dfs(int s_r, int s_c, int cnt)
{
	if (cnt > 3 || cnt > answer)
		return ;
	else
	{
		if(simulate(cnt))
			answer = min(answer, cnt);
	}

	for (int r = s_r; r < H; r++)
	{
		for (int c = s_c; c < N - 1; c++)
		{
			if (board[r][c] == 1 || (c - 1 >= 0 && board[r][c - 1] == 1))
				continue;

			board[r][c] = 1;
			dfs(r, c, cnt + 1);
			board[r][c] = 0;
		}
		s_c = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a - 1][b - 1] = 1;
	}
	dfs(0, 0, 0);
	if (answer == 4)
		answer = -1;
	cout << answer;
}