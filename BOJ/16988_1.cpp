// Baaaaaaaaaduk2 (Easy) 1회차 : 18분
// https://www.acmicpc.net/problem/16988
#include <iostream>
#include <queue>
using namespace std;

const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };
int N, M, answer;
int board[21][21];

void solve()
{
	bool visited[21][21];
	fill_n(visited[0], 21 * 21, 0);
	int total = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (board[r][c] == 2 && !visited[r][c])
			{
				bool flag = true;
				int cnt = 1;
				queue <pair<int, int>> q;
				q.push(make_pair(r,c));
				visited[r][c] = 1;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || board[nr][nc] == 1)
							continue;

						if (board[nr][nc] == 0)
							flag = false;
						else if (board[nr][nc] == 2)
						{
							q.push(make_pair(nr, nc));
							visited[nr][nc] = 1;
							cnt += 1;
						}
					}
				}
				if (flag)
					total += cnt;
			}
		}
	}
	answer = max(answer, total);
}
void dfs(int s_r, int s_c, int cnt)
{
	if (cnt == 2)
	{
		solve();
		return;
	}
	for (int r = s_r; r < N; r++)
	{
		for (int c = s_c; c < M; c++)
		{
			if (board[r][c] == 1 || board[r][c] == 2)
				continue;

			board[r][c] = 1;
			dfs(r, c, cnt + 1);
			board[r][c] = 0;
		}
		s_c = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	answer = 0;
	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
		}
	}
	dfs(0, 0, 0);
	cout << answer << '\n';
}