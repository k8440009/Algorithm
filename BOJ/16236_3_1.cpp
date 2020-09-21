// 아기 상어 3회
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <queue>
using namespace std;

struct SHARK
{
	int r, c, size;
	int cnt;
};

SHARK baby;

const int MAX = 20 + 2;
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N, answer;
int board[MAX][MAX];

bool solve()
{
	int visited[MAX][MAX];

	fill_n(visited[0], MAX * MAX, 0);

	int candi_dist = MAX * MAX + 1;
	pair <int,int> candi;
	queue <pair <int, SHARK> > q;

	candi.first = N + 1, candi.second = N + 1;
	q.push(make_pair(0, baby));
	visited[baby.r][baby.c] = 1;
	board[baby.r][baby.c] = 0;

	while (!q.empty())
	{
		pair <int, SHARK> data = q.front();
		q.pop();

		int cur_dist = data.first;
		SHARK cur = data.second;

		if (candi_dist != N + 1 && cur_dist > candi_dist)
			break;
		
		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.r + dr[dir], nc = cur.c + dc[dir];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N
				|| visited[nr][nc] || board[nr][nc] > cur.size)
				continue;
			
			if (board[nr][nc] != 0 && cur.size > board[nr][nc])
			{
				if (cur_dist + 1 <= candi_dist)
				{
					if (nr < candi.first)
						candi.first = nr, candi.second = nc, candi_dist = cur_dist + 1;
					else if (nr == candi.first && nc < candi.second)
						candi.first = nr, candi.second = nc, candi_dist = cur_dist + 1;
				}
			}

			SHARK next = baby;
			next.r = nr, next.c = nc;
			
			q.push(make_pair(cur_dist + 1, next));
			visited[next.r][next.c] = 1;
		}
	}

	// cout << candi.first << ' ' << candi.second << '\n';
	if (candi.first != N + 1)
	{
		baby.r = candi.first, baby.c = candi.second, baby.cnt += 1;
		board[baby.r][baby.c] = 0;
		if (baby.size == baby.cnt)
			baby.size += 1, baby.cnt = 0;
		answer += candi_dist;
		return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 9)
				baby.r = r, baby.c = c, baby.cnt = 0, baby.size = 2;
		}
	}

	while (true)
	{
		if (solve())
			break;
	}
	cout << answer << '\n';
}