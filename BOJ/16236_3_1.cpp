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

	int candi_dist = (N + 1) * (N + 1);
	pair <int,int> candi;
	queue <pair<int, SHARK> > q;

	q.push(make_pair(0, baby));
	visited[baby.r][baby.c] = 1;
	candi.first = N + 1, candi.second = N + 1;

	while (!q.empty())
	{
		pair<int,SHARK> data = q.front();
		q.pop();

		int dist = data.first;
		SHARK cur = data.second;

		if (candi.first != N + 1 && candi_dist > dist)
			break;

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.r + dr[dir], nc = cur.c + dc[dir];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || board[nr][nc] > cur.size)
				continue;
			
			if (board[nr][nc] == 0)
			{
				SHARK next;
				next.r = nr, next.c = nc;
				q.push(make_pair(dist + 1, next));
				visited[nr][nc] = 1;
			}
			else
			{
				if (cur.size > board[nr][nc])
				{
					if (dist + 1 < candi_dist)
						candi.first = nr, candi.second = nc, candi_dist = dist + 1;
					else if (dist == candi_dist)
					{
						if (nr < candi.first)
							candi.first = nr, candi.second = nc, candi_dist = dist + 1;
						else if (nr == candi.first && nc < candi.second)
							candi.second = nc, candi_dist = dist;
					}
				}

				SHARK next;
				next.r = nr, next.c = nc;
				q.push(make_pair(dist + 1, next));
				visited[nr][nc] = 1;
			}
		}
	}

	if (candi.first != N + 1)
	{
		baby.cnt += 1;
		board[candi.first][candi.second] = 0;
		if (baby.cnt == baby.size)
			baby.cnt = 0, baby.size += 1;
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
			{
				baby.r = r, baby.c = c, baby.cnt = 0, baby.size = 2;
				board[r][c] = 0;
			}
		}
	}

	while (true)
	{
		if (solve())
			break;
	}
	cout << answer << '\n';
}