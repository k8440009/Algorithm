// 미세먼지 안녕! 3회차 : 30분
// https://www.acmicpc.net/problem/17144
#include <iostream>
using namespace std;

const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };
int cur_board[52][52], next_board[52][52];
int R, C, T, answer;
int up_cleaner, down_cleaner;

void solve()
{
	// 1. 확산
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (cur_board[r][c] > 0)
			{
				int spread_dust = cur_board[r][c] / 5, spread_cnt = 0;
				for (int dir = 0; dir < 4; dir++)
				{
					int nr = r + dr[dir], nc = c + dc[dir];
					if (nr < 1 || nr >= R + 1 || nc < 1 || nc >= C + 1 || cur_board[nr][nc] == -1)
						continue;
					next_board[nr][nc] += spread_dust;
					spread_cnt++;
				}
				next_board[r][c] += (cur_board[r][c] - spread_dust * spread_cnt);
			}
		}
	}
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (cur_board[r][c] == -1)
				continue;
			cur_board[r][c] = next_board[r][c];
			next_board[r][c] = 0;
		}
	}
	// 2. 이동
	for (int r = up_cleaner - 1; r > 1; r--)
		cur_board[r][1] = cur_board[r - 1][1];
	for (int c = 1; c < C; c++)
		cur_board[1][c] = cur_board[1][c + 1];
	for (int r = 1; r < up_cleaner; r++)
		cur_board[r][C] = cur_board[r + 1][C];
	for (int c = C; c > 2; c--)
		cur_board[up_cleaner][c] = cur_board[up_cleaner][c - 1];
	cur_board[up_cleaner][2] = 0;

	for (int r = down_cleaner + 1; r < R; r++)
		cur_board[r][1] = cur_board[r + 1][1];
	for (int c = 1; c < C; c++)
		cur_board[R][c] = cur_board[R][c + 1];
	for (int r = R; r > down_cleaner; r--)
		cur_board[r][C] = cur_board[r - 1][C];
	for (int c = C; c > 2; c--)
		cur_board[down_cleaner][c] = cur_board[down_cleaner][c - 1];
	cur_board[down_cleaner][2] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	answer = 0;
	cin >> R >> C >> T;
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			cin >> cur_board[r][c];
			if (cur_board[r][c] == -1)
			{
				if (up_cleaner == 0)
					up_cleaner = r;
				else
					down_cleaner = r;
			}
		}
	}
	int time = 0;
	while (time < T)
	{
		solve();
		time++;
	}
	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++)
			if (cur_board[r][c] > 0)
				answer += cur_board[r][c];
	cout << answer << '\n';
}