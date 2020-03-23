// Gaaaaaaaaaarden
// https://www.acmicpc.net/problem/18809
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};
struct STATE
{
	int r, c, time, color;
};
int N, M, G, R;
int answer = 0;
int board[52][52];

vector<pair<int, int>> location;
vector<int> selected;

void bfs()
{
	int cnt = 0;
	int tmp_board[52][52];
	int visited[52][52];
	queue<STATE> q;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			tmp_board[r][c] = board[r][c];
	fill_n(visited[0], 52 * 52, 0);

	for (int i = 0; i < selected.size(); i++)
	{
		if (selected[i] == 1) // 초
		{
			STATE tmp;
			tmp.r = location[i].first, tmp.c = location[i].second;
			tmp.time = 0;
			tmp_board[tmp.r][tmp.c] = 2;
			visited[tmp.r][tmp.c] = 0;
			tmp.color = 2;
			q.push(tmp);
		}
		else if (selected[i] == 2) // 빨
		{
			STATE tmp;
			tmp.r = location[i].first, tmp.c = location[i].second;
			tmp.time = 0;
			tmp_board[tmp.r][tmp.c] = 3;
			visited[tmp.r][tmp.c] = 0;
			tmp.color = 3;
			q.push(tmp);
		}
	}

	while (!q.empty())
	{
		STATE cur = q.front();
		q.pop();

		if (tmp_board[cur.r][cur.c] == 4)
			continue;

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.r + dr[dir];
			int nc = cur.c + dc[dir];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M || tmp_board[nr][nc] == 0 || tmp_board[nr][nc] == 4)
				continue;

			if (tmp_board[nr][nc] == 1)
			{
				//cout << "check finish" << '\n';
				STATE next;
				next.r = nr, next.c = nc, next.time = cur.time + 1, next.color = cur.color;
				tmp_board[nr][nc] = cur.color;
				visited[nr][nc] = cur.time + 1;
				q.push(next);
			}
			else if (tmp_board[nr][nc] == 2)
			{
				STATE next;
				next.r = nr, next.c = nc, next.time = cur.time + 1;
				if (visited[nr][nc] == next.time && cur.color == 3)
				{
					tmp_board[nr][nc] = 4;
					cnt++;
				}
			}
			else if (tmp_board[nr][nc] == 3)
			{
				STATE next;
				next.r = nr, next.c = nc, next.time = cur.time + 1;
				if (visited[nr][nc] == next.time && cur.color == 2)
				{
					tmp_board[nr][nc] = 4;
					cnt++;
				}
			}
		}
	}
	if (answer < cnt)
		answer = cnt;
}

void picked()
{
	int n = location.size();
	for (int i = 0; i < G; i++)
		selected.push_back(1);
	for (int i = 0; i < R; i++)
		selected.push_back(2);
	for (int i = 0; i < n - G - R; i++)
		selected.push_back(0);
	sort(selected.begin(), selected.end());

	do
	{
		bfs();
	} while (next_permutation(selected.begin(), selected.end()));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> G >> R;

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 2)
			{
				location.push_back(make_pair(r, c));
				board[r][c] = 1;
			}
		}
	}

	// 뽑기 -> bfs()
	picked();
	cout << answer << '\n';
}