// 성곽 60분
// https://www.acmicpc.net/problem/2234
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 50 + 2;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

struct WALL
{
	int no, we , so, ea;
};

int M, N;
int start_room, max_room, sum_room;
vector <WALL> board[MAX][MAX];

void fillWall(int num, WALL &tmp)
{
	if (num / 8 == 1)
	{
		tmp.so = 1;
		num %= 8;
	}

	if (num / 4 == 1)
	{
		tmp.ea = 1;
		num %= 4;
	}

	if (num / 2 == 1)
	{
		tmp.no = 1;
		num %= 2;
	}

	if (num == 1)
	{
		tmp.we = 1;
	}

}

void solve()
{
	int visited[MAX][MAX];
	fill_n(visited[0], MAX * MAX, 0);

	for (int r = 0; r < M; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (!visited[r][c])
			{
				int room_cnt = 1;
				start_room += 1;
				queue <pair <int,int> > q;

				q.push(make_pair(r,c));
				visited[r][c] = 1;

				while (!q.empty())
				{
					pair <int,int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nr = cur.first + dr[dir], nc = cur.second + dc[dir];

						if (nr < 0 || nr >= M || nc < 0 || nc >= N || visited[nr][nc])
							continue;
						if (dir == 0 && board[cur.first][cur.second][0].no == 1)
							continue;
						else if (dir == 1 && board[cur.first][cur.second][0].ea == 1)
						{
							continue;
						}
						else if (dir == 2 && board[cur.first][cur.second][0].so == 1)
							continue;
						else if (dir == 3 && board[cur.first][cur.second][0].we == 1)
							continue;
						
						q.push(make_pair(nr, nc));
						visited[nr][nc] = 1;
						room_cnt += 1;
					}
				}
				max_room = max(max_room, room_cnt);
			}
		}
	}

	for (int r = 0; r < M; r++)
	{
		for (int c = 0; c < N; c++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				if (dir == 0 && board[r][c][0].no == 1)
					board[r][c][0].no = 0;
				else if (dir == 1 && board[r][c][0].ea == 1)
					board[r][c][0].ea = 0;
				else if (dir == 2 && board[r][c][0].so == 1)
					board[r][c][0].so = 0;
				else if (dir == 3 && board[r][c][0].we == 1)
					board[r][c][0].we = 0;
				else
					continue;
				
				fill_n(visited[0], MAX * MAX, 0);

				int room_cnt = 1;
				queue <pair <int,int> > q;

				q.push(make_pair(r,c));
				visited[r][c] = 1;

				while (!q.empty())
				{
					pair <int,int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nr = cur.first + dr[dir], nc = cur.second + dc[dir];

						if (nr < 0 || nr >= M || nc < 0 || nc >= N || visited[nr][nc])
							continue;
						if (dir == 0 && board[cur.first][cur.second][0].no == 1)
							continue;
						else if (dir == 1 && board[cur.first][cur.second][0].ea == 1)
							continue;
						else if (dir == 2 && board[cur.first][cur.second][0].so == 1)
							continue;
						else if (dir == 3 && board[cur.first][cur.second][0].we == 1)
							continue;
						
						q.push(make_pair(nr, nc));
						visited[nr][nc] = 1;
						room_cnt += 1;
					}
				}
				sum_room = max(sum_room, room_cnt);

				if (dir == 0)
					board[r][c][0].no = 1;
				else if (dir == 1)
					board[r][c][0].ea = 1;
				else if (dir == 2)
					board[r][c][0].so = 1;
				else if (dir == 3)
					board[r][c][0].we = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int r = 0; r < M; r++)
	{
		for (int c = 0; c < N; c++)
		{
			int num;
			cin >> num;
			WALL wall;
			wall.we = 0, wall.ea = 0, wall.no = 0, wall.so = 0;

			fillWall(num, wall);
			board[r][c].push_back(wall);
		}
	}

	solve();

	cout << start_room << '\n';
	cout << max_room << '\n';
	cout << sum_room << '\n';
}