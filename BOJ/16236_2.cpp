// 아기 상어 2회 : 90분
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <queue>
using namespace std;

struct FISH
{
	int r, c, size, cnt, dist;
};

const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };
FISH shark;

int N, answer;
int board[21][21], dist[21][21];

bool solve()
{
	queue <pair<int, int>> q;
	
	fill_n(dist[0], 21 * 21, -1);
	q.push(make_pair(shark.r, shark.c));
	dist[shark.r][shark.c] = 0;

	FISH target;
	target.r = N, target.c = N, target.dist = 30 * 30;

	while (!q.empty())
	{

		pair<int, int> cur = q.front();
		q.pop();

		if (board[cur.first][cur.second] != 0 && board[cur.first][cur.second] < shark.size)
		{
			if (dist[cur.first][cur.second] < target.dist)
				target.r = cur.first, target.c = cur.second, target.dist = dist[cur.first][cur.second];
			else if (dist[cur.first][cur.second] == target.dist)
			{
				if (target.r > cur.first)
					target.r = cur.first, target.c = cur.second;
				else if(target.r == cur.first)
				{
					if (target.c > cur.second)
						target.c = cur.second;
				}
			}
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || dist[nr][nc] > -1 || board[nr][nc] > shark.size)
				continue;
			q.push(make_pair(nr, nc));
			dist[nr][nc] = dist[cur.first][cur.second] + 1;
		}
	}
	if (target.r != N)
	{
		board[target.r][target.c] = 0;
		shark.r = target.r, shark.c = target.c, shark.cnt += 1;
		if (shark.size == shark.cnt)
		{
			shark.cnt = 0;
			shark.size += 1;
		}
		answer += target.dist;
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	answer = 0;

	cin >> N;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 9)
			{
				shark.r = r, shark.c = c, shark.cnt = 0, shark.size = 2;
				board[r][c] = 0;
			}
		}
	}
	while (true)
	{
		if (!solve())
			break;
	}
	cout << answer << '\n';
}