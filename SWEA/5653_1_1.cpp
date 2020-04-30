// 5653. [모의 SW 역량테스트] 줄기세포배양
#include <iostream>
#include <vector>
using namespace std;

// state : 0 (없음), state : 1 (비활성화), state : 2 (활성화), state: 3 (사망)
struct CELL
{
	int state, life, time, max_life;
};

const int MAX_SIZE = 1001;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int N, M, K;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		cin >> N >> M >> K;
		int answer = 0;
		CELL board[MAX_SIZE][MAX_SIZE];
		for (int r = 0; r < MAX_SIZE; r++)
			for (int c = 0; c < MAX_SIZE; c++)
				board[r][c] = {0, 0, 0, 0};
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				int tmp;
				cin >> tmp;
				if (tmp > 0)
				{
					CELL tmp_cell;
					tmp_cell.life = tmp, tmp_cell.max_life = tmp, tmp_cell.time = tmp, tmp_cell.state = 1;
					board[r + 50][c + 50] = tmp_cell;
				}
			}
		}

		int time = 0;
		while (time <= K)
		{
			for (int r = 0; r < MAX_SIZE; r++)
			{
				for (int c = 0; c < MAX_SIZE; c++)
				{
					if (board[r][c].state == 1 || board[r][c].state == 2)
					{
						// 1. 비활성화
						if (board[r][c].state == 1)
						{
							if (board[r][c].time == 0)
								board[r][c].state = 2, board[r][c].time = board[r][c].life;
							else
								board[r][c].time -= 1;
						}
						// 2. 활성화
						else if (board[r][c].state == 2)
						{
							board[r][c].time -= 1;
							if (board[r][c].time == board[r][c].life - 1)
							{
								// 3. 번식
								for (int dir = 0; dir < 4; dir++)
								{
									int nr = r + dr[dir], nc = c + dc[dir];
									if (board[nr][nc].state == 0)
									{
										board[nr][nc].state = 1,
										board[nr][nc].life = board[r][c].life,
										board[nr][nc].time = board[nr][nc].life,
										board[nr][nc].max_life = board[nr][nc].life;
									}
									else if (board[nr][nc].state == 1 && board[nr][nc].time == board[nr][nc].life)
									{
										if (board[r][c].max_life > board[nr][nc].max_life)
										{
											board[nr][nc].life = board[r][c].life,
											board[nr][nc].time = board[nr][nc].life,
											board[nr][nc].max_life = board[nr][nc].life;
										}
									}
								}
							}
							if (board[r][c].time == 0)
								board[r][c].state = 3;
						}
					}
				}
			}
			time++;
		}
		for (int r = 0; r < MAX_SIZE; r++)
		{
			for (int c = 0; c < MAX_SIZE; c++)
			{
				if (board[r][c].state == 1 || board[r][c].state == 2)
					answer++;
			}
		}
		cout << "#" << ts << ' ' << answer << '\n';
	}
}