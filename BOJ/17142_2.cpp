// 연구소 3 2회차 - 90분
// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct STATE
{
	int r, c, time;
};

const int INF = 987654321;
const int dr[] = { 1,-1,0,0 };
const int dc[] = { 0,0,1,-1 };

int board[52][52], selected[12];
int N, M;
int safe, answer;

vector<pair<int, int>> virus_loc;

void solve()
{
	int visited[52][52], safe_zone = safe, time = 0;
	fill_n(visited[0], 52 * 52, -1);

	queue <STATE> q;
	for (int i = 0; i < virus_loc.size(); i++)
	{
		if (selected[i])
		{
			STATE tmp;
			tmp.r = virus_loc[i].first, tmp.c = virus_loc[i].second, tmp.time = 0;
			q.push(tmp);
			visited[tmp.r][tmp.c] = 0;
		}
	}
	while (!q.empty())
	{
		STATE cur = q.front();
		q.pop();

		if (safe_zone == 0)
			break;

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.r + dr[dir], nc = cur.c + dc[dir];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 1 || visited[nr][nc] >= 0)
				continue;

			STATE tmp;

			tmp.r = nr, tmp.c = nc, tmp.time = cur.time + 1;
			visited[nr][nc] = cur.time + 1;
			q.push(tmp);
			if(board[nr][nc] == 0)
				safe_zone -= 1;
		}
	}

	if (safe_zone == 0)
	{
		int time = 0;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (visited[r][c] > time)
					time = visited[r][c];
			}
		}
		answer = min(answer, time);
	}
}

void dfs(int cur, int prev)
{
	if (cur == M)
	{
		solve();
		return;
	}
	if (cur >= virus_loc.size())
		return;

	for (int i = 0; i < virus_loc.size(); i++)
	{
		if (selected[i] || prev > i)
			continue;
		selected[i] = 1;
		dfs(cur + 1, i);
		selected[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	answer = INF;
	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 0)
				safe += 1;
			else if (board[r][c] == 2)
				virus_loc.push_back(make_pair(r, c));
		}
	}
	if (safe > 0)
	{
		dfs(0, 0);
		if (answer == INF)
			answer = -1;
	}
	else
		answer = 0;
	cout << answer << '\n';
}