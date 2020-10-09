// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 10 + 2;
const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,-1,1};

struct INFO
{
	int ry, rx, by, bx, count;
};

int N, M, answer;
INFO info;

char board[MAX][MAX];

void bfs()
{
	int visited[MAX][MAX][MAX][MAX];
	queue <INFO> q;
	q.push(info);
	visited[info.ry][info.rx][info.by][info.bx] = 1;

	while (!q.empty())
	{
		INFO cur = q.front();
		q.pop();

		if (cur.count > 10 || cur.count > answer)
			break;
		
		if (board[cur.ry][cur.rx] == 'O' && board[cur.by][cur.bx] != 'O')
		{
			answer = cur.count;
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int next_ry = cur.ry, next_rx = cur.rx;
			int next_by = cur.by, next_bx = cur.bx;

			while (true)
			{
				if (board[next_ry][next_rx] != '#' && board[next_ry][next_rx] != 'O')
					next_ry += dr[dir], next_rx += dc[dir];
				else
				{
					if (board[next_ry][next_rx] == '#')
						next_ry -= dr[dir], next_rx -= dc[dir];
					break;
				}
			}

			while (true)
			{
				if (board[next_by][next_bx] != '#' && board[next_by][next_bx] != 'O')
					next_by += dr[dir], next_bx += dc[dir];
				else
				{
					if (board[next_by][next_bx] == '#')
						next_by -= dr[dir], next_bx -= dc[dir];
					break;
				}
			}

			if (next_ry == next_by && next_rx == next_bx)
			{
				if (board[next_ry][next_rx] != 'O')
				{
					int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
					if (red_dist > blue_dist)
						next_ry -= dr[dir], next_rx -= dc[dir];
					else
						next_by -= dr[dir], next_bx -= dc[dir];
				}
			}

			if (visited[next_ry][next_rx][next_by][next_bx] == 0)
			{
				visited[next_ry][next_rx][next_by][next_bx] = 1;
                INFO next;
                next.ry = next_ry, next.rx = next_rx;
                next.by = next_by, next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 'R')
				info.ry = r, info.rx = c;
			else if (board[r][c] == 'B')
				info.by = r, info.bx = c;
		}
	}
	answer = 11;
	info.count = 0;
	bfs();
	if (answer == 11)
		answer = -1;
	cout << answer;
}