// 5653. [모의 SW 역량테스트] 줄기세포배양
#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 352;
const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};
// state : 0 (없음), state : 1 (비활성화), state : 2 (활성화), state: 3 (사망)
struct CELL
{
	int state, life, time;
};

int N,M,K, answer;
CELL board[2][MAX_SIZE][MAX_SIZE];

void print_board(int cur_time)
{
	cout << '\n';
	for(int r = 0; r < N; r++)
	{
		for(int c = 0; c < M; c++)
		{
			cout << board[cur_time][r][c].life << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for(int r = 0; r < N; r++)
	{
		for(int c = 0; c < M; c++)
		{
			cout << board[cur_time][r][c].state << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("sample.txt", "r", stdin);
	int tc;
	cin >> tc;
	for(int ts = 1; ts <= tc; ts++)
	{
		answer = 0;
		cin >> N >> M >> K;
		for(int r = 0; r < N + K + 2; r++)
			for(int c = 0; c < M + K + 2; c++)
			{
				board[0][r][c].state = 0;
				board[1][r][c].state = 0;
			}
		int size = K / 2;
		for(int r = size + 1; r < size + N + 1; r++)
		{
			for(int c = size + 1; c < size + M + 1; c++)
			{
				cin >> board[0][r][c].life;
				if (board[0][r][c].life > 0)
				{
					board[0][r][c].state = 1;
					board[0][r][c].time = board[0][r][c].life;
				}
			}
		}
		N += (K + 2);
		M += (K + 2);
		int time = 0, cur_time = 0;
		while (time < K)
		{
			for(int r = 0; r < N; r++)
			{
				for(int c = 0; c < M; c++)
				{
					// 죽음
					if(board[cur_time][r][c].state == 3)
					{
						board[1 - cur_time][r][c].state = 3;
						continue;
					}
					// 비 활성화
					else if(board[cur_time][r][c].state == 1)
					{
						board[1 - cur_time][r][c].life = board[cur_time][r][c].life;
						board[1 - cur_time][r][c].time = board[cur_time][r][c].time - 1;
						if(board[1 - cur_time][r][c].time == 0)
						{
							board[1 - cur_time][r][c].state = 2;
							board[1 - cur_time][r][c].time = board[cur_time][r][c].life;
						}
						else
							board[1 - cur_time][r][c].state = 1;			
					}
					else if(board[cur_time][r][c].state == 2)
					{
						if(board[cur_time][r][c].time == board[cur_time][r][c].life)
						{
							for(int dir = 0; dir < 4; dir++)
							{
								int nr = r + dr[dir], nc = c + dc[dir];
								if(board[1 - cur_time][nr][nc].state == 0)
								{
									board[1 - cur_time][nr][nc].state = 1;
									board[1 - cur_time][nr][nc].life = board[cur_time][r][c].life;
									board[1 - cur_time][nr][nc].time = board[cur_time][r][c].life;
								}
								else if (board[1 - cur_time][nr][nc].state == 1 && board[1 - cur_time][nr][nc].life == board[1 - cur_time][nr][nc].time)
								{
									if(board[cur_time][r][c].life > board[1 - cur_time][nr][nc].life)
									{
										board[1 - cur_time][nr][nc].life = board[cur_time][r][c].life;
										board[1 - cur_time][nr][nc].time = board[cur_time][r][c].life;
									}
								}
							}
						}
						board[1 - cur_time][r][c].time = board[cur_time][r][c].time - 1;
						board[1 - cur_time][r][c].life = board[cur_time][r][c].life;
						if(board[1 - cur_time][r][c].time == 0)
							board[1 - cur_time][r][c].state = 3;
						else
							board[1 - cur_time][r][c].state = 2;
					}
				}
			}
			cur_time = 1 - cur_time;
			time++;
		}
		//print_board(cur_time);
		for(int r = 0; r < N; r++)
		{
			for(int c = 0; c < M; c++)
			{
				if(board[cur_time][r][c].state == 1 || board[cur_time][r][c].state == 2)
					answer++;
			}
		}
		
		cout << "#" << ts << ' ' << answer << '\n';
	}
}
