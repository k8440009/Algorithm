// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460

#include <iostream>
using namespace std;

const int MAX = 10 + 2;
const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };

struct INFO
{
	int ry, rx, by, bx, cnt;
};

int N, M, answer = 11;
char board[MAX][MAX];

INFO move(INFO cur, int dir)
{
	INFO next = cur;
	int nr = cur.ry, nc = cur.rx;

	while (true)
	{
		if (board[nr][nc] == '#')
		{
			nr -= dr[dir], nc -= dc[dir];
			next.ry = nr, next.rx = nc;
			break;
		}
		else if (board[nr][nc] == 'O')
		{
			next.ry = nr, next.rx = nc;
			break;
		}
		nr += dr[dir], nc += dc[dir];
	}

	nr = cur.by, nc = cur.bx;
	while (true)
	{
		if (board[nr][nc] == '#')
		{
			nr -= dr[dir], nc -= dc[dir];
			next.by = nr, next.bx = nc;
			break;
		}
		else if (board[nr][nc] == 'O')
		{
			next.by = nr, next.bx = nc;
			break;
		}
		nr += dr[dir], nc += dc[dir];
	}

	if (board[next.ry][next.rx] != 'O' && (next.ry == next.by && next.rx == next.bx))
	{
		int red_dist = abs(next.ry - cur.ry) + abs(next.rx - cur.rx);
		int blue_dist = abs(next.by - cur.by) + abs(next.bx - cur.bx);
		if (red_dist > blue_dist)
			next.ry -= dr[dir], next.rx -= dc[dir];
		else
			next.by -= dr[dir], next.bx -= dc[dir];
	}
	next.cnt = cur.cnt + 1;
	return next;
}

void dfs(INFO cur)
{
	if (cur.cnt > 10 || cur.cnt > answer)
		return;

	if (board[cur.by][cur.bx] == 'O')
		return;

	if (board[cur.ry][cur.rx] == 'O')
	{
		answer = cur.cnt;
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		INFO next = cur;
		next = move(cur, dir);
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	INFO start;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 'R')
			{
				start.ry = r, start.rx = c;
				board[r][c] = '.';
			}
			else if (board[r][c] == 'B')
			{
				start.by = r, start.bx = c;
				board[r][c] = '.';
			}
		}
	}
	start.cnt = 0;
	dfs(start);
	if (answer == 11)
		answer = -1;
	cout << answer;
}