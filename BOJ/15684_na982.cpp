// 사다리 조작
// https://www.acmicpc.net/problem/15684
#include <iostream>
using namespace std;

int N,M,H, answer = 4;
int board[32][11];

bool check_ladder()
{
	for (int c = 1; c <= N; c++)
	{
		int	s_r = 1, s_c = c;
		while (s_r <= H)
		{
			if (board[s_r][s_c] == 1)
				s_c += 1;
			else if (board[s_r][s_c - 1] == 1)
				s_c -= 1;
			s_r++;
		}
		if (s_c != c)
			return false;
	}
	return true;
}

void dfs(int s_r, int s_c, int cnt)
{
	if (cnt >= answer)
		return ;
	if (check_ladder())
	{
		answer = min(answer, cnt);
		return;
	}
	if (cnt == 3)
		return ;
	
	for (int r = s_r; r <= H; r++)
	{
		for (int c = s_c; c < N; c++)
		{
			if (board[r][c] == 0 && board[r][c + 1] == 0 && board[r][c - 1] == 0)
			{
				board[r][c] = 1;
				dfs(r, c, cnt + 1);
				board[r][c] = 0;
			}
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
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}

	if (check_ladder())
		answer = 0;
	else
		dfs (1, 1, 0);

	if (answer == 4)
		answer = -1;

	cout << answer << '\n';
}