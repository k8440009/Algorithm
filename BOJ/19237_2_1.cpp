// 어른 상어 2회차 : 90분
// https://www.acmicpc.net/problem/19237
#include <iostream>
using namespace std;

struct SHARK
{
	int r, c, d;
	int priority[4][4];
};

const int MAX = 20 + 1;
const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };
int N, M, K, answer;
SHARK shark[MAX * MAX];
// 0 : 현재 위치에 있는 상어
// 1 : 상어 냄새 주인
// 2 : 상어 냄새 지속 시간
int board[MAX][MAX][3];

void solve()
{
	int time = 0;
	int kill_shark = 0;
	while (time <= 1000)
	{
		time++;
		// 냄새
		for (int i = 0; i < M; i++)
		{
			if (shark[i].r == -1)
				continue;
			int r = shark[i].r;
			int c = shark[i].c;
			board[r][c][1] = i + 1;
			board[r][c][2] = K;
		}
		// 복사
		int next_board[MAX][MAX][3];
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				next_board[r][c][0] = board[r][c][0];
				next_board[r][c][1] = board[r][c][1];
				next_board[r][c][2] = board[r][c][2];
			}
		}
		// 이동
		for (int i = 0; i < M; i++)
		{
			if (shark[i].r == -1)
				continue;

			bool is_move = false;
			int sr = shark[i].r;
			int sc = shark[i].c;
			int sd = shark[i].d;
			for (int d = 0; d < 4; d++)
			{
				int nd = shark[i].priority[sd][d];
				int nr = sr + dr[nd];
				int nc = sc + dc[nd];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N || next_board[nr][nc][2] != 0)
					continue;
				is_move = true;
				if (next_board[nr][nc][0] >= 1)
				{
					shark[i].r = -1;
					next_board[sr][sc][0] = 0;
					++kill_shark;
				}
				else
				{
					shark[i].r = nr;
					shark[i].c = nc;
					shark[i].d = nd;
					next_board[sr][sc][0] = 0;
					next_board[nr][nc][0] = i + 1;
				}
				break;
			}

			if (!is_move)
			{
				for (int d = 0; d < 4; d++)
				{
					int nd = shark[i].priority[sd][d];
					int nr = sr + dr[nd];
					int nc = sc + dc[nd];

					if (nr < 0 || nr >= N || nc < 0 || nc >= N || next_board[nr][nc][1] != i + 1)
						continue;

					shark[i].r = nr;
					shark[i].c = nc;
					shark[i].d = nd;
					next_board[sr][sc][0] = 0;
					next_board[nr][nc][0] = i + 1;
					break;
				}
			}
		}
		// 냄새 제거
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (next_board[r][c][2] == 0)
					continue;

				--next_board[r][c][2];
				if (next_board[r][c][2] == 0)
					next_board[r][c][1] = 0;
			}
		}

		if (kill_shark == M - 1)
			break;

		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				board[r][c][0] = next_board[r][c][0];
				board[r][c][1] = next_board[r][c][1];
				board[r][c][2] = next_board[r][c][2];
			}
		}
	}
	if (time <= 1000)
		answer = time;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c][0];
			if (board[r][c][0] > 0)
			{
				int idx = board[r][c][0] - 1;
				shark[idx].r = r;
				shark[idx].c = c;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> shark[i].d;
		--shark[i].d;
	}

	for (int n = 0; n < M; n++)
	{
		for (int d = 0; d < 4; d++)
		{
			for (int c = 0; c < 4; c++)
			{
				cin >> shark[n].priority[d][c];
				--shark[n].priority[d][c];
			}
		}
	}
	answer = -1;
	solve();
	cout << answer;
}