// 낚시왕 2회차 : 35분
// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct SHARK
{
	int r,c,speed, dir, size;
};
const int dr[] = { 0,-1,1,0,0 };
const int dc[] = { 0,0,0,1,-1 };
int R, C, M, answer;

vector <SHARK> cur_board[102][102], next_board[102][102];

int change_dir(int dir)
{
	if (dir == 1)
		return 2;
	else if (dir == 2)
		return 1;
	else if (dir == 3)
		return 4;
	else if (dir == 4)
		return 3;
}

void solve()
{
	int people_c = 0;
	while (true)
	{
		people_c++;
		if (people_c == C + 1)
			break;
		// 낚시
		for (int r = 1; r <= R; r++)
		{
			if (cur_board[r][people_c].size() > 0)
			{
				answer += cur_board[r][people_c][0].size;
				cur_board[r][people_c].pop_back();
				break;
			}
		}
		// 상어 이동
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (!cur_board[r][c].empty())
				{
					SHARK shark = cur_board[r][c][0];
					int cnt = 0, end_cnt;
					if (shark.dir == 1 || shark.dir == 2)
						end_cnt = (shark.speed % (R * 2 - 2));
					else
						end_cnt = (shark.speed % (C * 2 - 2));
					while (cnt < end_cnt)
					{
						int nr = shark.r + dr[shark.dir], nc = shark.c + dc[shark.dir];
						if (nr < 1 || nr >= R + 1 || nc < 1 || nc >= C + 1)
							shark.dir = change_dir(shark.dir);
						else
						{
							shark.r = nr, shark.c = nc;
							cnt++;
						}
					}
					// 이동
					if (next_board[shark.r][shark.c].size() == 0)
						next_board[shark.r][shark.c].push_back(shark);
					else
					{
						if (shark.size > next_board[shark.r][shark.c][0].size)
						{
							next_board[shark.r][shark.c].pop_back();
							next_board[shark.r][shark.c].push_back(shark);
						}
					}
					cur_board[r][c].clear();
				}
			}
		}
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (next_board[r][c].empty())
					continue;
				cur_board[r][c] = next_board[r][c];
				next_board[r][c].clear();
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		SHARK tmp;

		cin >> tmp.r >> tmp.c >> tmp.speed >> tmp.dir >> tmp.size;
		cur_board[tmp.r][tmp.c].push_back(tmp);
	}
	if(M != 0)
		solve();
	cout << answer << '\n';
}