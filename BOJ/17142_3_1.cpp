// 연구소 3회차 : 40분
// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct POS
{
	int r, c;
};

const int MAX = 50 + 2;
const int dr[] = { 1,-1,0,0 };
const int dc[] = { 0,0,1,-1 };
int N, M, zone, answer = 987654321;
int board[MAX][MAX];
vector <POS> virus;
int check[10];

void bfs()
{
	int safe_zone = zone;
	queue <POS> q;
	int visited[MAX][MAX];
	fill_n(visited[0], MAX * MAX, -1);

	for (int i = 0; i < virus.size(); i++)
	{
		if (check[i])
		{
			POS tmp;
			tmp.r = virus[i].r, tmp.c = virus[i].c;
			q.push(tmp);
			visited[tmp.r][tmp.c] = 0;
		}
	}

	while (!q.empty())
	{
		POS cur = q.front();
		q.pop();

		if (safe_zone == 0)
		{
			int time = 0;
			for (int r = 0; r < N; r++)
				for (int c = 0; c < N; c++)
					time = max(time, visited[r][c]);
			answer = min(answer, time);
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.r + dr[dir];
			int nc = cur.c + dc[dir];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 1 || visited[nr][nc] > -1)
				continue;

			if (board[nr][nc] == 0)
				--safe_zone;

			POS tmp;
			tmp.r = nr, tmp.c = nc;
			q.push(tmp);
			visited[nr][nc] = visited[cur.r][cur.c] + 1;
		}
	}
}

void dfs(int cur, int cnt)
{
	if (cnt == M)
	{
		bfs();
		return;
	}

	for (int i = cur; i < virus.size(); i++)
	{
		if (check[i])
			continue;

		check[i] = 1;
		dfs(i, cnt + 1);
		check[i] = 0;
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
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 0)
				zone++;
			else if (board[r][c] == 2)
			{
				POS tmp;
				tmp.r = r, tmp.c = c;
				virus.push_back(tmp);
			}
		}
	}
	if (zone == 0)
		answer = 0;
	else
		dfs(0,0);

	if (answer == 987654321)
		answer = -1;
	cout << answer;
}