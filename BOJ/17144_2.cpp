// 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 50 + 1;
const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};
int R, C, T;

vector<pair<int, int>> cleaner;
int board[MAX][MAX];

void execute()
{
	int start_r = cleaner[0].first;

	for (int r = start_r - 1; r - 1 >= 0; r--)
		board[r][0] = board[r - 1][0];
	for (int c = 0; c + 1 < C; c++)
		board[0][c] = board[0][c + 1];
	for (int r = 0; r + 1 <= start_r; r++)
		board[r][C - 1] = board[r + 1][C - 1];
	for (int c = C - 1; c - 1 >= 0; c--)
		board[start_r][c] = board[start_r][c - 1];
	board[start_r][1] = 0;

	start_r = cleaner[1].first;
	for (int r = start_r + 1; r + 1 < R; r++)
		board[r][0] = board[r + 1][0];
	for (int c = 0; c + 1 < C; c++)
		board[R - 1][c] = board[R - 1][c + 1];
	for (int r = R - 1; r - 1 >= start_r; r--)
		board[r][C - 1] = board[r - 1][C - 1];
	for (int c = C - 1; c - 1 >= 0; c--)
		board[start_r][c] = board[start_r][c - 1];
	board[start_r][1] = 0;
}
void move_dust()
{
	int new_board[MAX][MAX];
	fill_n(new_board[0], MAX * MAX, 0);
	new_board[cleaner[0].first][cleaner[0].second] = -1;
	new_board[cleaner[1].first][cleaner[1].second] = -1;

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (board[r][c] > 0)
			{
				int cnt = 0;
				int spread = board[r][c] / 5;
				for (int dir = 0; dir < 4; dir++)
				{
					int nr = r + dr[dir];
					int nc = c + dc[dir];

					if (nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] == -1)
						continue;
					new_board[nr][nc] += spread;
					cnt++;
				}
				new_board[r][c] += board[r][c] - (spread)*cnt;
			}
		}
	}

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			board[r][c] = new_board[r][c];
}

void print()
{
	int total = 0;
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
		{
			if (board[r][c] > 0)
				total += board[r][c];
		}
	cout << total << '\n';
}
void solve()
{
	for (int t = 0; t < T; t++)
	{
		move_dust();
		execute();
	}
}

void init()
{
	cin >> R >> C >> T;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == -1)
				cleaner.push_back(make_pair(r, c));
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