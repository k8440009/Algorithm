// 게리맨더링 2
// https://www.acmicpc.net/problem/17779

#include <iostream>
using namespace std;

const int MAX = 20 + 2;

int N;
int board[MAX][MAX];
int visited[MAX][MAX];

void print_board()
{
	cout << '\n';
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << visited[r][c] << ' ';
		}
		cout << '\n';
	}
}

void forth(int x, int y, int d1, int d2)
{
	for (int d = 0; d <= d1; d++)
	{
		if (x + d2 + d >= N || y + d2 - d < 0)
			break;
		visited[x + d2 + d][y + d2 - d] = 1;
	}
}

void third(int x, int y, int d1, int d2)
{
	for (int d = 0; d <= d2; d++)
	{
		if (x + d1 + d >= N || y -d1 + d2 < 0)
			break;
		visited[x + d1 + d][y -d1 + d2] = 1;
	}
}

void second(int x, int y, int d1, int d2)
{
	for (int d = 0; d <= d2; d++)
	{
		if (x + d >= N || y + d >= N)
			break;
		visited[x + d][y + d] = 1;
	}	
}

void first(int x, int y, int d1, int d2)
{
	for (int d = 0; d <= d1; d++)
	{
		if (x + d >= N || y - d < 0)
			break;
		visited[x + d][y - d] = 1;
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

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int d1 = 1; d1 <= N; d1++)
			{
				for (int d2 = 1; d2 <= N; d2++)
				{
					fill_n(visited[0], MAX * MAX, 0);
					if (x + d1 >= N || y - d1 < 0)
						continue;
					if (x + d2 >= N || y + d2 >= N)
						continue;
					if (x + d1 >= N || y - d1 < 0)
						continue;
					if (x + d2 >= N || y + d2 >= N)
						continue;

					first(x, y, d1, d2);
					second(x, y, d1, d2);
					third(x, y, d1, d2);
					forth(x, y, d1, d2);
					print_board();
				}
			}
		}
	}
}