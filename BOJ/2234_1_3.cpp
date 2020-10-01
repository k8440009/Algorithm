// 성곽
// https://www.acmicpc.net/problem/2234
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 50 + 2;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

int N,M;
int cntRoom, sumRoom, maxRoom;
int board[MAX][MAX];
int visited[MAX][MAX];

void bfs_two(int r, int c)
{
	for (int r = 0; r < M; r++)
	{
		for (int c = 0; c < N; c++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nr = r + dr[dir], nc = c + dc[dir];
				if (nr < 0 || nr >= M || nc < 0 || nc >= N)
					continue;
				// and 연산으로 벽을 0으로 만듬
				if (board[r][c] & (1 << dir))
			}
		}
	}
}

void bfs_one(int r, int c)
{
	queue <pair <int,int>> q;
	q.push(make_pair(r,c));
	visited[r][c] = 1;
	int cnt = 0;

	while (!q.empty())
	{
		pair <int,int> cur = q.front();
		q.pop();
		cnt++;

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = r + dr[dir], nc = c + dc[dir];
			if (nr < 0 || nr >= M || nc < 0 || nc >= N || visited[nr][nc])
				continue;
			if (board[r][c] && (1 << dir))
				continue;

			q.push(make_pair(nr, nc));
			visited[nr][nc] = 1;
		}
	}
	maxRoom = max(maxRoom, cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int r = 0; r < M; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
	
	for (int r = 0; r < M; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (visited[r][c])
			{
				cntRoom++;
				solve(r, c);
			}
		}
	}
}