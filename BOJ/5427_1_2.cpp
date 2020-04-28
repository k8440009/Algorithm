// 불
// https://www.acmicpc.net/problem/5427
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct STATE
{
	int r, c, state, time;
};
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int W, H;

char board[1002][1002];
bool visited[1002][1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("sample.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		fill_n(visited[0], 1002 * 1002, 0);
		int answer = 987654321;
		cin >> W >> H;
		queue<STATE> q;
		int p_r, p_c;
		for (int r = 0; r < H; r++)
		{
			for (int c = 0; c < W; c++)
			{
				cin >> board[r][c];
				if (board[r][c] == '*')
				{
					STATE tmp;
					tmp.r = r, tmp.c = c, tmp.state = 1, tmp.time = 0;
					q.push(tmp);
				}
				else if (board[r][c] == '@')
				{
					p_r = r, p_c = c;
					board[r][c] = '.';
					visited[r][c] = 1;
				}
			}
		}
		STATE tmp;
		tmp.r = p_r, tmp.c = p_c, tmp.time = 0, tmp.state = 2;
		q.push(tmp);

		bool flag = 1;
		while (!q.empty() && flag)
		{
			STATE cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nr = cur.r + dr[dir];
				int nc = cur.c + dc[dir];

				if (nr < 0 || nr >= H || nc < 0 || nc >= W)
				{
					if (cur.state == 2)
					{
						answer = cur.time + 1;
						flag = 0;
						break;
					}
					else
						continue;
				}

				if (board[nr][nc] == '*' || board[nr][nc] == '#' || visited[nr][nc] == 1)
					continue;

				STATE next;
				next.r = nr, next.c = nc, next.time = cur.time + 1, next.state = cur.state;
				if (cur.state == 1)
					board[nr][nc] = '*';
				else if (cur.state == 2)
					visited[nr][nc] = 1;
				q.push(next);
			}
		}

		if (answer == 987654321)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << answer << '\n';
	}
}