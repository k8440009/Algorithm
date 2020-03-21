// 2번 - Gaaaaaaaaaarden, 18809
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ADD
{
	int r, c, time;
	char color;
};

const int MAX = 50 + 1;
int answer = 0;
int N, M, G, R;
int board[MAX][MAX];
int visited[MAX][MAX];

vector<pair<int, int>> location;

void board_copy(int desc, int src)
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			desc[r][c] = src[r][c];
}
void play()
{
	int flower = 0;
	int test_board[MAX][MAX];
	int time[MAX][MAX];
	board_copy(test_board, board);
	fill_n(time[0], MAX * MAX, 0);
	queue<ADD> q;
	// 정했다고 합시다.
	for (int i = 0; i < location.size(); i++)
	{
		if (select[i])
		{
			ADD tmp;
			tmp.r = location[i].first;
			tmp.c = location[i].second;
			tmp.color = g;
			// tmp.color = r;
			tmp.time = 0;
			test_board[tmp.r][tmp.c] = 3;
		}
	}

	while (!q.empty())
	{
		ADD cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int now_time = cur.time;
			int nr = cur.r + dr[dir];
			int nc = cur.c + dc[dir];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || test_board[nr][nc] == 1)
				continue;
			// 빨강
			if (test_board[nr][nc] == 3)
			{
				if (time[nr][nc] == now_time)
				{
					flower++;
					test_board[nr][nc] = 1;
				}
				else
				{
					ADD tmp;
					tmp.r = nr;
					tmp.c = nc;
					tmp.color = g;
					tmp.time = now_time + 1;
					time[tmp.r][tmp.c] = now_time;
					visited[tmp.r][tmp.c] = 1;
					q.push(tmp)
				}
			}
			// 파랑
			else if (test_board[nr][nc] == 4)
			{
				if (time[nr][nc] == now_time)
				{
					flower++;
					test_board[nr][nc] = 1;
				}
				else
				{
					ADD tmp;
					tmp.r = nr;
					tmp.c = nc;
					tmp.color = r;
					tmp.time = now_time + 1;
					time[tmp.r][tmp.c] = now_time;
					visited[tmp.r][tmp.c] = 1;
					q.push(tmp)
				}
			}
		}
	}
}

void dfs(int curr, int cnt)
{
	if (cnt != 0 && cnt % 2 == 0)
	{
		play();
	}
	if (curr == location.size())
	{
		return;
	}

	location[curr] = 1;
	dfs(curr + 1, cnt + 1);
	location[curr] = 0;
	dfs(curr + 1, cnt);
}
void solve()
{
	dfs(0, 0);
}

void init()
{
	cin >> N >> M >> G >> R;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (board[r][c] == 2)
				location.push_back(make_pair(r, c));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();
}