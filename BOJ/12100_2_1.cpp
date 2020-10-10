// 2048 (easy) 2회차
// https://www.acmicpc.net/problem/12100
/*
4
2 2 2 2
0 0 0 0
0 0 0 0
0 0 0 0
*/
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 20 + 2;

int N, answer;
int board[MAX][MAX];

void print_board(int src[MAX][MAX])
{
	cout << '\n';
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << src[r][c] << ' ';
		}
		cout << '\n';
	}
}
int find_max(int src[MAX][MAX])
{
	int	max_data = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			max_data = max(max_data, src[r][c]);
	return max_data;
}

void board_copy(int desc[MAX][MAX], int src[MAX][MAX])
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			desc[r][c] = src[r][c];
}

void move(int src[MAX][MAX], int dir)
{
	int tmp[MAX][MAX];
	int visited[MAX][MAX];

	fill_n(tmp[0], MAX * MAX, 0);
	fill_n(visited[0], MAX * MAX, 0);

	if (dir == 0)
	{
		for (int c = 0; c < N; c++)
		{
			int r = 0, idx = 0;
			vector <int> data;

			while (r < N)
			{
				if (src[r][c] > 0)
					data.push_back(src[r][c]);
				r++;
			}
			r = 0;
			while (r < N && data.size() != idx)
			{
				if (tmp[r][c] == 0)
				{
					tmp[r][c] = data[idx];
					idx++;
				}
				else
				{
					if (tmp[r][c] == data[idx] && !visited[r][c])
					{
						tmp[r][c] *= 2;
						visited[r][c] = 1;
						idx++;
					}
					else
						r++;
				}
			}
		}
	}
	else if (dir == 1)
	{
		for (int c = 0; c < N; c++)
		{
			int r = N - 1, idx = 0;
			vector <int> data;

			while (r >= 0)
			{
				if (src[r][c] > 0)
					data.push_back(src[r][c]);
				r--;
			}
			r = N - 1;
			while (r >= 0 && data.size() != idx)
			{
				if (tmp[r][c] == 0)
				{
					tmp[r][c] = data[idx];
					idx++;
				}
				else
				{
					if (tmp[r][c] == data[idx] && !visited[r][c])
					{
						tmp[r][c] *= 2;
						visited[r][c] = 1;
						idx++;
					}
					else
						r--;
				}
			}
		}
	}
	else if (dir == 2)
	{
		for (int r = 0; r < N; r++)
		{
			int c = 0, idx = 0;
			vector <int> data;

			while (c < N)
			{
				if (src[r][c] > 0)
					data.push_back(src[r][c]);
				c++;
			}
			c = 0;
			while (c < N && data.size() != idx)
			{
				if (tmp[r][c] == 0)
				{
					tmp[r][c] = data[idx];
					idx++;
				}
				else
				{
					if (tmp[r][c] == data[idx] && !visited[r][c])
					{
						tmp[r][c] *= 2;
						visited[r][c] = 1;
						idx++;
					}
					else
						c++;
				}
			}
		}
	}
	else if (dir == 3)
	{
		for (int r = 0; r < N; r++)
		{
			int c = N - 1, idx = 0;
			vector <int> data;

			while (c >= 0)
			{
				if (src[r][c] > 0)
					data.push_back(src[r][c]);
				c--;
			}
			c = N - 1;
			while (c >= 0 && data.size() != idx)
			{
				if (tmp[r][c] == 0)
				{
					tmp[r][c] = data[idx];
					idx++;
				}
				else
				{
					if (tmp[r][c] == data[idx] && !visited[r][c])
					{
						tmp[r][c] *= 2;
						visited[r][c] = 1;
						idx++;
					}
					else
						c--;
				}
			}
		}
	}
	board_copy(src, tmp);
}


void dfs(int cur[MAX][MAX], int cnt)
{
	if (cnt == 5)
	{
		answer = max(answer, find_max(cur));
		//print_board(cur);
		return ;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		int next[MAX][MAX];

		board_copy(next, cur);
		move(next, dir);
		dfs(next, cnt + 1);
		board_copy(next, cur);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
	dfs(board, 0);
	cout << answer;
}