// 감시
// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 8 + 1;
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
int N, M, answer = 987654321;
int new_board[MAX][MAX];
int board[MAX][MAX];
int visited[MAX];
vector<pair<int, int>> cctv;

void right(int dir, int s_r, int s_c)
{
	int r = s_r;
	int c = s_c;
	int new_dir = (0 + dir) % 4;

	while (true)
	{
		int nr = r + dr[new_dir];
		int nc = c + dc[new_dir];

		if (nr < 0 || nr >= N || nc < 0 || nc >= M || new_board[nr][nc] == 6)
			break;
		if (new_board[nr][nc] == 0)
			new_board[nr][nc] = -1;
		r = nr;
		c = nc;
	}
}
void down(int dir, int s_r, int s_c)
{
	int r = s_r;
	int c = s_c;
	int new_dir = (1 + dir) % 4;

	while (true)
	{
		int nr = r + dr[new_dir];
		int nc = c + dc[new_dir];

		if (nr < 0 || nr >= N || nc < 0 || nc >= M || new_board[nr][nc] == 6)
			break;
		if (new_board[nr][nc] == 0)
			new_board[nr][nc] = -1;
		r = nr;
		c = nc;
	}
}

void left(int dir, int s_r, int s_c)
{
	int r = s_r;
	int c = s_c;
	int new_dir = (2 + dir) % 4;

	while (true)
	{
		int nr = r + dr[new_dir];
		int nc = c + dc[new_dir];

		if (nr < 0 || nr >= N || nc < 0 || nc >= M || new_board[nr][nc] == 6)
			break;
		if (new_board[nr][nc] == 0)
			new_board[nr][nc] = -1;
		r = nr;
		c = nc;
	}
}
void up(int dir, int s_r, int s_c)
{
	int r = s_r;
	int c = s_c;
	int new_dir = (3 + dir) % 4;

	while (true)
	{
		int nr = r + dr[new_dir];
		int nc = c + dc[new_dir];

		if (nr < 0 || nr >= N || nc < 0 || nc >= M || new_board[nr][nc] == 6)
			break;
		if (new_board[nr][nc] == 0)
			new_board[nr][nc] = -1;
		r = nr;
		c = nc;
	}
}

void check_sight()
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			new_board[r][c] = board[r][c];

	for (int i = 0; i < cctv.size(); i++)
	{
		// cctv 번호, index
		int cur_r = cctv[i].first;
		int cur_c = cctv[i].second;
		int cctv_num = board[cur_r][cur_c];
		int dir = visited[i];

		if (cctv_num == 1)
		{
			right(dir, cur_r, cur_c);
		}
		else if (cctv_num == 2)
		{
			//if (dir % 2 != 0)
			//	dir++;
			left(dir, cur_r, cur_c);
			right(dir, cur_r, cur_c);
		}
		else if (cctv_num == 3)
		{
			up(dir, cur_r, cur_c);
			right(dir, cur_r, cur_c);
		}
		else if (cctv_num == 4)
		{
			left(dir, cur_r, cur_c);
			up(dir, cur_r, cur_c);
			right(dir, cur_r, cur_c);
		}
		else
		{
			left(dir, cur_r, cur_c);
			up(dir, cur_r, cur_c);
			right(dir, cur_r, cur_c);
			down(dir, cur_r, cur_c);
		}
	}

	int temp = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (new_board[r][c] == 0)
				temp++;
		}
	}

	if (temp < answer)
		answer = temp;
}

void dfs(int cur)
{
	if (cctv.size() == cur)
	{
		check_sight();
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		visited[cur] = dir;
		dfs(cur + 1);
	}
}

void solve()
{
	dfs(0);
}

void init()
{
	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] >= 1 && board[r][c] <= 5)
			{
				cctv.push_back(make_pair(r, c));
			}
		}
	}
}

void print()
{
	cout << answer << '\n';
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