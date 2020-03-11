// 아기상어
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20 + 1;
const int INF = 987654321;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

struct FISH
{
	int row, col, size;
	int cnt = 0;
	int time = 0;
};

FISH shark;

int board[MAX][MAX];

int N;
int g_flag;

void bfs()
{
	FISH candi;
	candi.row = MAX;
	candi.col = MAX;
	candi.time = INF;
	int visited[MAX][MAX];
	queue<FISH> q;

	fill_n(visited[0], MAX * MAX, 0);
	q.push(shark);
	visited[shark.row][shark.col] = 1;

	while (!q.empty())
	{
		FISH cur = q.front();
		q.pop();

		if (board[cur.row][cur.col] != 0 && shark.size > board[cur.row][cur.col] && cur.time <= candi.time)
		{
			g_flag = 1;
			candi.time = cur.time;
			if (cur.row < candi.row)
			{
				candi.row = cur.row;
				candi.col = cur.col;
			}
			else if (cur.row == candi.row && cur.col < candi.col)
			{
				candi.row = cur.row;
				candi.col = cur.col;
			}
		}

		if (cur.time > candi.time)
			break;

		for (int dir = 0; dir < 4; dir++)
		{
			FISH next;
			next.row = cur.row + dr[dir];
			next.col = cur.col + dc[dir];
			next.time = cur.time + 1;
			next.size = board[next.row][next.col];

			if (next.row < 0 || next.row >= N || next.col < 0 || next.col >= N || visited[next.row][next.col])
				continue;
			else if (next.size > shark.size)
				continue;
			q.push(next);
			visited[next.row][next.col] = 1;
		}
	}

	if (g_flag)
	{
		shark.row = candi.row, shark.col = candi.col, shark.time = candi.time;
		board[shark.row][shark.col] = 0;
		shark.cnt++;
		if (shark.cnt == shark.size)
		{
			shark.size++;
			shark.cnt = 0;
		}
	}
}

void solve()
{
	while (1)
	{
		g_flag = 0;
		bfs();
		if (!g_flag)
			break;
	}
}

void print()
{
	cout << shark.time << '\n';
}

void init()
{
	cin >> N;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 9)
			{
				shark.row = r, shark.col = c, shark.size = 2;
				board[r][c] = 0;
			}
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
	print();
}