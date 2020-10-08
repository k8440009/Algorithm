// 경사로 4회차
// https://www.acmicpc.net/problem/14890
#include <iostream>
using namespace std;

const int MAX = 100 + 2;
int N,L, answer;
int board[MAX][MAX];
int visited[MAX][MAX];

void print_board()
{
	cout << '\n';
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << board[r][c] << ' ';
		}
		cout << '\n';
	}
}

bool setLadder(int r)
{

	int c = 1;
	while (c < N)
	{
		if (board[r][c - 1] != board[r][c])
		{
			if (board[r][c - 1] + 1 == board[r][c])
			{
				int cnt = -1;
				int s_c = c - 1;
				int basis = board[r][c - 1];
				while (++cnt != L)
				{
					if (board[r][s_c] != basis || s_c < 0 || visited[r][s_c])
						return false;
					visited[r][s_c] = 1;
					s_c--;
				}
				c++;
			}
			else if (board[r][c - 1]  == board[r][c] + 1)
			{
				int cnt = -1;
				int s_c = c;
				int basis = board[r][c];
				while (++cnt != L)
				{
					if (board[r][s_c] != basis || s_c >= N || visited[r][s_c])
						return false;
					visited[r][s_c] = 1;
					s_c++;
				}
				c += L;		
			}
			else
				return false;
		}
		else
			c++;
	}
	return true;
}

void rotate()
{
	int tmp[MAX][MAX];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			tmp[r][c] = board[r][c];

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			board[r][c] = tmp[N - 1 - c][r];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];

	for (int r = 0; r < N; r++)
	{
		if (setLadder(r))
			answer++;
	}
	rotate();
	// print_board();
	fill_n(visited[0], MAX * MAX, 0);
	for (int r = 0; r < N; r++)
	{
		if (setLadder(r))
			answer++;
	}
	cout << answer << '\n';
}