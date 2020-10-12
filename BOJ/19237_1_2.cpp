// 어른 상어
// https://www.acmicpc.net/problem/19237
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20 + 2;
const int dr[] = { 0,-1,1,0,0 };
const int dc[] = { 0,0,0,-1,1 };

struct SHARK
{
	int r, c, d;
	int priority[5][5];
};

int N, M, K, answer;
// 0 : 원판, 1 : 냄새 주인, 2 : 냄새의 남은 시간
int board[MAX][MAX][3];

SHARK shark[MAX * MAX];

void solve()
{
	int time = 0;
	int kill_shark = 0;
	while (time <= 1000)
	{
		++time;
	
		int new_board[MAX][MAX][3];
		fill_n(new_board[0][0], MAX * MAX * 3, 0);

		for (int r = 1; r <= N; r++)
		{
			for (int c = 1; c <= N; c++)
			{
				new_board[r][c][0] = board[r][c][0];
				new_board[r][c][2] = board[r][c][2];
				if (new_board[r][c][2] > 0)
					--new_board[r][c][2];
				if (new_board[r][c][2] > 0)
					new_board[r][c][1] = board[r][c][1];
			}
		}

		for (int i = 1; i <= M; i++)
		{
			int s_r = shark[i].r, s_c = shark[i].c, s_d = shark[i].d;

			if (s_r == -1)
				continue;
			bool is_move = false;
			for (int d = 1; d <= 4; d++)
			{
				int nd = shark[i].priority[s_d][d];
				int nr = s_r + dr[nd], nc = s_c + dc[nd];

				if (nr < 1 || nr > N || nc < 1 || nc > N || board[nr][nc][2] != 0)
					continue;
					
				is_move = true;
				new_board[s_r][s_c][0] = 0;
				// 상어 움직임
				if (new_board[nr][nc][0] == 0)
				{
					new_board[nr][nc][0] = i, new_board[nr][nc][1] = i, new_board[nr][nc][2] = K;
					shark[i].r = nr, shark[i].c = nc, shark[i].d = nd;
				}
				else
				{
					++kill_shark;
					shark[i].r = -1;
				}
				break;
			}

			if (is_move == false)
			{
				for (int d = 1; d <= 4; d++)
				{
					int nd = shark[i].priority[s_d][d];
					int nr = s_r + dr[nd], nc = s_c + dc[nd];

					if (nr < 1 || nr > N || nc < 1 || nc > N)
						continue;

					if (board[nr][nc][2] != 0 && board[nr][nc][1] != i)
						continue;
					
					new_board[s_r][s_c][0] = 0;
					// 상어 움직임
					if (new_board[nr][nc][0] == 0)
					{
						new_board[nr][nc][0] = i, new_board[nr][nc][1] = i, new_board[nr][nc][2] = K;
						shark[i].r = nr, shark[i].c = nc, shark[i].d = nd;
					}
					else
					{
						++kill_shark;
						shark[i].r = -1;
					}
					break;
				}
			}
		}

		if (kill_shark == M - 1)
			break;

		for (int r = 1; r <= N; r++)
		{
			for (int c = 1; c <= N; c++)
			{
				board[r][c][0] = new_board[r][c][0];
				board[r][c][1] = new_board[r][c][1];
				board[r][c][2] = new_board[r][c][2];
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
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			cin >> board[r][c][0];
			if (board[r][c][0] != 0)
			{
				int shark_number = board[r][c][0];
				shark[shark_number].r = r;
				shark[shark_number].c = c;
				board[r][c][1] = board[r][c][0];
				board[r][c][2] = K;
			}
		}
	}

	for (int i = 1; i <= M; i++)
		cin >> shark[i].d;

	for (int i = 1; i <= M; i++)
	{
		for (int d = 1; d <= 4; d++)
		{
			cin >> shark[i].priority[d][1] >> shark[i].priority[d][2] >> shark[i].priority[d][3] >> shark[i].priority[d][4];
		}
	}

	answer = -1;
	solve();
	cout << answer;
}

/*
**	참고자료
**	강의 : https://www.youtube.com/watch?v=siY0q4u3GgE
**	코드 : https://www.youtube.com/watch?v=6TlAeqK3zXA
**	https://na982.tistory.com/128
*/