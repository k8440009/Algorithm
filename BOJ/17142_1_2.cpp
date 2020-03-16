// 연구소 3
// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 50 + 1;
const int INF = 987654321;
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};

int N, M, answer = INF;
int board[MAX][MAX];
int selected[11];
int g_cnt = 0;
vector<pair<int, int>> location;

void bfs()
{
	int blank = g_cnt;
	int new_board[MAX][MAX];
	int visited[MAX][MAX];
	int time[MAX][MAX];
	fill_n(visited[0], MAX * MAX, 0);
	fill_n(time[0], MAX * MAX, 0);
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			new_board[r][c] = board[r][c];
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < location.size(); i++)
	{
		if (selected[i])
		{
			int r = location[i].first, c = location[i].second;
			q.push(make_pair(0, make_pair(r, c)));
			new_board[r][c] = 2;
			visited[r][c] = 1;
			time[r][c] = 0;
		}
	}
	while (!q.empty())
	{
		if (blank == 0)
			break;
		pair<int, pair<int, int>> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int now = cur.first;
			int nr = cur.second.first + dr[dir];
			int nc = cur.second.second + dc[dir];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || new_board[nr][nc] == 1)
				continue;
			if (new_board[nr][nc] == 0)
			{
				new_board[nr][nc] = 2;
				visited[nr][nc] = 1;
				time[nr][nc] = now + 1;
				blank--;
				q.push(make_pair(now + 1, make_pair(nr, nc)));
			}
			else if (new_board[nr][nc] == 2)
			{
				visited[nr][nc] = 1;
				time[nr][nc] = now + 1;
				q.push(make_pair(now + 1, make_pair(nr, nc)));
			}
		}
	}

	if (blank == 0)
	{
		int tmp = 0;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (time[r][c] > tmp)
					tmp = time[r][c];
			}
		}
		if (answer > tmp)
			answer = tmp;
	}
}

void dfs(int cur, int cnt)
{
	if (cnt == M)
	{
		bfs();
		return;
	}
	if (cur == location.size())
		return;

	selected[cur] = 1;
	dfs(cur + 1, cnt + 1);
	selected[cur] = 0;
	dfs(cur + 1, cnt);
}
void solve()
{
	if (g_cnt == 0)
		answer = 0;
	else
	{
		dfs(0, 0);
		if (answer == INF)
			answer = -1;
	}
	cout << answer << '\n';
}

void init()
{
	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 2)
				location.push_back(make_pair(r, c));
			else if (board[r][c] == 0)
				g_cnt++;
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