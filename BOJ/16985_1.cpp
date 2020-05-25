// Maaaaaaaaaze 1회차 : 3시간
// https://www.acmicpc.net/problem/16985
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct POINT
{
	int r, c, z, cnt;
};
const int INF = 987654321;
const int dr[] = { 0,0,-1,1,0,0 };
const int dc[] = { -1,1,0,0,0,0 };
const int dz[] = { 0,0,0,0,-1,1 };

int answer;
int board[4][5][5][5];
int test_board[5][5][5];

vector <int> order = { 0,1,2,3,4 };
vector<pair<int, int>> s_point = { {0,0}, {0,4}, {4,0}, {4,4} }, e_point = { {4,4},{4,0}, {0,4}, {0,0} };

void print_board(int dir, int num)
{
	cout << "dir : " << dir << ' ' << "num : " << num << '\n';
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			cout << board[dir][num][r][c] << ' ';
		}
		cout << '\n';
	}
}
void rotate()
{
	for (int num = 0; num < 5; num++)
	{
		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 5; c++)
				board[1][num][r][c] = board[0][num][4 - c][r];

		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 5; c++)
				board[2][num][r][c] = board[1][num][4 - c][r];

		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 5; c++)
				board[3][num][r][c] = board[2][num][4 - c][r];
	}
}

void bfs()
{
	for (int i = 0; i < 4; i++)
	{
		queue<POINT> q;
		bool visited[5][5][5];
		fill_n(visited[0][0], 5 * 5 * 5, 0);

		if (test_board[0][s_point[i].first][s_point[i].second] == 0 || test_board[4][e_point[i].first][e_point[i].second] == 0)
			continue;
		else
		{
			POINT tmp;
			tmp.r = s_point[i].first, tmp.c = s_point[i].second, tmp.z = 0, tmp.cnt = 0;
			q.push(tmp);
			visited[0][tmp.r][tmp.c] = 1;
		}

		while (!q.empty())
		{
			POINT cur = q.front();
			q.pop();

			// cout << cur.r << ' ' << cur.c << ' ' << cur.z << '\n';
			if (cur.z == 4 && cur.r == e_point[i].first && cur.c == e_point[i].second)
			{
				answer = min(answer, cur.cnt);
				break;
			}
			else if (answer == 12)
				break;

			for (int dir = 0; dir < 6; dir++)
			{
				int nr = cur.r + dr[dir], nc = cur.c + dc[dir], nz = cur.z + dz[dir];
				if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || nz < 0 || nz >= 5)
					continue;
				else if (test_board[nz][nr][nc] == 0 || visited[nz][nr][nc])
					continue;

				POINT next;
				next.r = nr, next.c = nc, next.z = nz, next.cnt = cur.cnt + 1;
				q.push(next);
				visited[nz][nr][nc] = 1;
			}
		}
	}

}


void dfs(int curr)
{
	if (curr == 5)
	{
		bfs();
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 5; c++)
				test_board[curr][r][c] = board[dir][order[curr]][r][c];
		dfs(curr + 1);
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("sample.txt", "r", stdin);
	answer = INF;
	for (int num = 0; num < 5; num++)
	{
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				cin >> board[0][num][r][c];
			}
		}
	}
	rotate();
	do
	{
		dfs(0);
	} while (next_permutation(order.begin(), order.end()));
	if (answer == INF)
		answer = -1;
	cout << answer << '\n';
}