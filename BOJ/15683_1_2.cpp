// 감시
// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct CCTV
{
	int type, r, c;
};

const int MAX = 8 + 1;
const int rot_size[] = {4, 2, 4, 4, 1};
int N, M, cctv_cnt, answer = 987654321;
int board[MAX][MAX];
CCTV cctv[MAX];

void update(int dir, CCTV cctv)
{
	dir = (dir % 4);
	if (dir == 0)
	{
		for (int c = cctv.c + 1; c < M; c++)
		{
			if (board[cctv.r][c] == 6)
				break;
			board[cctv.r][c] = -1;
		}
	}
	else if (dir == 1)
	{
		for (int r = cctv.r - 1; r >= 0; r--)
		{
			if (board[r][cctv.c] == 6)
				break;
			board[r][cctv.c] = -1;
		}
	}
	else if (dir == 2)
	{
		for (int c = cctv.c - 1; c >= 0; c--)
		{
			if (board[cctv.r][c] == 6)
				break;
			board[cctv.r][c] = -1;
		}
	}
	else if (dir == 3)
	{
		for (int r = cctv.r + 1; r < N; r++)
		{
			if (board[r][cctv.c] == 6)
				break;
			board[r][cctv.c] = -1;
		}
	}
}

void board_copy(int desc[MAX][MAX], int src[MAX][MAX])
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			desc[r][c] = src[r][c];
		}
	}
}

void check_sight()
{
	int sight_cnt = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (board[r][c] == 0)
				sight_cnt++;
		}
	}
	if (answer > sight_cnt)
		answer = sight_cnt;
}
void dfs(int curr)
{
	if (curr == cctv_cnt)
	{
		check_sight();
		return;
	}

	int backup[MAX][MAX];
	int type = cctv[curr].type;
	for (int dir = 0; dir < rot_size[type]; dir++)
	{
		board_copy(backup, board);
		// map update
		if (type == 0)
		{
			update(dir, cctv[curr]);
		}
		else if (type == 1)
		{
			update(dir, cctv[curr]);
			update(dir + 2, cctv[curr]);
		}
		else if (type == 2)
		{
			update(dir, cctv[curr]);
			update(dir + 1, cctv[curr]);
		}
		else if (type == 3)
		{
			update(dir, cctv[curr]);
			update(dir + 1, cctv[curr]);
			update(dir + 2, cctv[curr]);
		}
		else if (type == 4)
		{
			update(dir, cctv[curr]);
			update(dir + 1, cctv[curr]);
			update(dir + 2, cctv[curr]);
			update(dir + 3, cctv[curr]);
		}
		dfs(curr + 1);
		board_copy(board, backup);
	}
}
void solve()
{
	dfs(0);
}
void init()
{
	cin >> N >> M;
	cctv_cnt = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] >= 1 && board[r][c] <= 5)
			{
				cctv[cctv_cnt].r = r;
				cctv[cctv_cnt].c = c;
				cctv[cctv_cnt].type = board[r][c] - 1;
				cctv_cnt++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();
	cout << answer << '\n';
}