// 낚시왕 3회차 :
// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100 + 2;
const int dr[] = {0,-1,1,0,0};
const int dc[] = {0,0,0,1,-1};

struct SHARK
{
	int r, c;
	int speed, dir, size;
};

vector <SHARK> board[MAX][MAX];
int R, C, M;

void move()
{
	vector <SHARK> next[MAX][MAX];

	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (!board[r][c].empty())
			{
				SHARK cur = board[r][c][0];
				if (cur.dir == 1 || cur.dir == 2)
				{
					int nr, nc;
					int balance = cur.speed % (2 * (R - 1));
					int cnt = balance;
					while (cnt > 0)
					{
						nr = cur.r + dr[cur.dir], nc = cur.c + dc[cur.dir];
						if (nr < 1 || nr > R || nc < 1 || nc > C)
						{
							if (cur.dir == 1)
								cur.dir = 2;
							else
								cur.dir = 1;
							continue;
						}
						cur.r = nr, cur.c = nc;
						cnt--;
					}
					if (!next[cur.r][cur.c].empty())
					{
						if (cur.size > next[cur.r][cur.c][0].size)
						{
							next[cur.r][cur.c].pop_back();
							next[cur.r][cur.c].push_back(cur);
						}
					}
					else
						next[cur.r][cur.c].push_back(cur);
				
				}
				else
				{
					int balance = cur.speed % (2 * (C - 1));
					int cnt = balance;
					int nr, nc;
					while (cnt > 0)
					{
						nr = cur.r + dr[cur.dir], nc = cur.c + dc[cur.dir];
						if (nr < 1 || nr > R || nc < 1 || nc > C)
						{
							if (cur.dir == 3)
								cur.dir = 4;
							else
								cur.dir = 3;
							continue;
						}
						cur.r = nr, cur.c = nc;
						cnt--;
					}
					if (!next[cur.r][cur.c].empty())
					{
						if (cur.size > next[cur.r][cur.c][0].size)
						{
							next[cur.r][cur.c].pop_back();
							next[cur.r][cur.c].push_back(cur);
						}
					}
					else
						next[cur.r][cur.c].push_back(cur);
				}
			}
		}
	}	
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			board[r][c].clear();
			if (!next[r][c].empty())
				board[r][c] = next[r][c];
		}
	}
}

void print_board()
{
	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			if (!board[r][c].empty())
				cout << board[r][c][0].size << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
}
int	fishing(int c)
{
	int r = 1, size = 0;
	/*
	cout << '\n';
	cout << "loc : " << c << '\n';
	print_board();
	*/
	while (r <= R)
	{
		if (!board[r][c].empty())
		{
			size = board[r][c][0].size;
			board[r][c].pop_back();
			break;
		}
		r++;
	}
	return (size);
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
		board[tmp.r][tmp.c].push_back(tmp);
	}

	int i = 0;
	int answer = 0;
	while (i <= C)
	{
		i++;
		answer += fishing(i);
		move();
	}
	cout << answer << '\n';
}