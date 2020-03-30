// 낚시왕
// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FISH
{
	int r, c;
	int size;
	int speed;
	int dir;
};

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, 1, -1};

int R, C, M;
vector<FISH> board[102][102];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		FISH shark;
		// 상어위치(r,c), 속력, 이동방향, 크기
		cin >> shark.r >> shark.c >> shark.speed >> shark.dir >> shark.size;
		shark.dir -= 1;
		board[shark.r][shark.c].push_back(shark);
	}
	// 1. 낚시왕이 이동 1~C
	// 2. 1~R까지상어 찾고, 잡음
	// 3. 상어 움직임 -> 속력에 따라 -> 상어끼리 잡아먹음
	int time = 0;
	int answer = 0;
	int start = 1;
	while (start <= C)
	{
		for (int r = 1; r <= R; r++)
		{
			if (board[r][start].empty())
				continue;
			else
			{
				answer += board[r][start][0].size;
				board[r][start].pop_back();
				break;
			}
		}
		vector<FISH> tmp[102][102];
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				if (board[i][j].empty())
					continue;
				else
				{
					FISH shark = board[i][j][0];
					int r = shark.r, c = shark.c, speed = shark.speed, dir = shark.dir;
					int rotate = 0;
					if (dir == 0 || dir == 1)
						rotate = (R - 1) * 2;
					else if (dir == 2 || dir == 3)
						rotate = (C - 1) * 2;

					speed %= rotate;
					for (int sp = 0; sp < speed; sp++)
					{
						int nr = r + dr[dir];
						int nc = c + dc[dir];

						if (nr < 1 || nr >= R + 1 || nc < 1 || nc >= C + 1)
						{
							if (dir == 0)
								dir = 1;
							else if (dir == 1)
								dir = 0;
							else if (dir == 2)
								dir = 3;
							else if (dir == 3)
								dir = 2;
							nr = r + dr[dir];
							nc = c + dc[dir];
						}
						r = nr;
						c = nc;
					}
					shark.r = r, shark.c = c, shark.dir = dir;
					tmp[shark.r][shark.c].push_back(shark);
				}
			}
		}
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				board[i][j].clear();
				if (tmp[i][j].size() == 0)
					continue;
				else if (tmp[i][j].size() == 1)
					board[i][j].push_back(tmp[i][j][0]);
				else
				{
					FISH max_shark = tmp[i][j][0];
					for (int k = 1; k < tmp[i][j].size(); k++)
					{
						FISH candi = tmp[i][j][k];
						if (candi.size > max_shark.size)
							max_shark = candi;
					}
					board[i][j].push_back(max_shark);
				}
			}
		}
		// 증가
		start += 1;
	}
	cout << answer << '\n';
}