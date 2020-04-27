// 2382. [모의 SW 역량테스트] 미생물 격리
#include <iostream>
using namespace std;

struct SWARM
{
	int cnt, dir, max_cnt;
};

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, -1, 1};

int N, M, K;
SWARM now_board[102][102];
SWARM next_board[102][102];

void move()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (now_board[r][c].cnt > 0)
			{
				int dir = now_board[r][c].dir;
				int nr = r + dr[dir], nc = c + dc[dir];
				// 1. 약품
				if (nr == 0 || nr == N - 1 || nc == 0 || nc == N - 1)
				{
					next_board[nr][nc].cnt = now_board[r][c].cnt / 2;
					if (dir == 1)
						next_board[nr][nc].dir = 2;
					else if (dir == 2)
						next_board[nr][nc].dir = 1;
					else if (dir == 3)
						next_board[nr][nc].dir = 4;
					else if (dir == 4)
						next_board[nr][nc].dir = 3;
				}
				else
				{
					// 2. 값이 존재하는 경우
					if (next_board[nr][nc].max_cnt > 0)
					{
						if (now_board[r][c].cnt > next_board[nr][nc].max_cnt)
						{
							next_board[nr][nc].max_cnt = now_board[r][c].cnt;
							next_board[nr][nc].dir = now_board[r][c].dir;
						}
						next_board[nr][nc].cnt += now_board[r][c].cnt;
					}
					else
					{
						next_board[nr][nc].cnt = now_board[r][c].cnt;
						next_board[nr][nc].dir = now_board[r][c].dir;
						next_board[nr][nc].max_cnt = next_board[nr][nc].cnt;
					}
				}
			}
		}
	}
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			now_board[r][c] = next_board[r][c], next_board[r][c] = {0, 0, 0};
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		int answer = 0;
		cin >> N >> M >> K;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				now_board[r][c] = {0, 0, 0};
		for (int i = 0; i < K; i++)
		{
			int tmp_r, tmp_c, tmp_cnt, tmp_dir;
			cin >> tmp_r >> tmp_c >> tmp_cnt >> tmp_dir;
			now_board[tmp_r][tmp_c] = {tmp_cnt, tmp_dir, tmp_cnt};
		}
		for (int time = 0; time < M; time++)
			move();
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
			{
				answer += now_board[r][c].cnt;
			}
		cout << '#' << ts << ' ' << answer << '\n';
	}
}