// 미세먼지 안녕! 4회차 : 33분
// https://www.acmicpc.net/problem/17144
#include <iostream>
using namespace std;

const int MAX = 50 + 2;
const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};

int R,C,T, answer;
int board[MAX][MAX];

int cleanTop = -1, cleanBot = -1;

void board_copy(int disc[MAX][MAX], int src[MAX][MAX])
{
	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++)
			disc[r][c] = src[r][c];	
}

void solve()
{
	int next_board[MAX][MAX];
	fill_n(next_board[0], MAX * MAX, 0);

	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (board[r][c] > 0)
			{
				int spread_cnt = 0;
				int div_dust = board[r][c] / 5;
				for (int dir = 0; dir < 4; dir++)
				{
					int nr = r + dr[dir], nc = c + dc[dir];
					if (nr < 1 || nr > R || nc < 1 || nc > C || board[nr][nc] == -1)
						continue;
					
					next_board[nr][nc] += div_dust;
					spread_cnt++;
				}
				next_board[r][c] += (board[r][c] - div_dust * spread_cnt);
			}
		}
	}

	next_board[cleanTop][1] = -1, next_board[cleanBot][1] = -1;
	board_copy(board, next_board);

	// 공기 청정기
	for (int r = cleanTop - 1; r - 1 >= 1; r--)
		board[r][1] = board[r - 1][1];
	for (int c = 1; c + 1 <= C; c++)
		board[1][c] = board[1][c + 1];
	for (int r = 1; r + 1 <= cleanTop; r++)
		board[r][C] = board[r + 1][C];
	for (int c = C; c - 1 >= 2; c--)
		board[cleanTop][c] = board[cleanTop][c - 1];
	board[cleanTop][2] = 0;

	for (int r = cleanBot + 1; r + 1 <= R; r++)
		board[r][1] = board[r + 1][1];
	for (int c = 1; c + 1 <= C; c++)
		board[R][c] = board[R][c + 1];
	for (int r = R; r - 1 >= cleanBot; r--)
		board[r][C] = board[r - 1][C];
	for (int c = C; c - 1 >= 2; c--)
		board[cleanBot][c] = board[cleanBot][c - 1];
	board[cleanBot][2] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> T;
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == -1)
			{
				if (cleanTop == -1)
					cleanTop = r;
				else
					cleanBot = r;
			}
		}
	}

	while (T--)
	{
		solve();
	}

	for (int r = 1; r <= R; r++)
		for (int c = 1; c <=C; c++)
			if (board[r][c] > 0)
				answer += board[r][c];

	cout << answer << '\n';
}