#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, R, C;
int stiky[12][12];
int board[42][42];

void rotate()
{
	int tmp[12][12];

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			tmp[r][c] = stiky[r][c];

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			stiky[i][j] = tmp[r - 1 - j][i];
		}
	}

	swap(R, C);
}
bool check()
{
	for (int r = 0; r <= N - R; r++)
	{
		// (r,c)에 모눈종이의 (0,0)이 올라간다.
		for (int c = 0; c <= M - C; c++)
		{
			bool flag = true;
			for (int i = 0; i < R; i++)
			{
				if (!flag)
					break;
				for (int j = 0; j < C; c++)
				{
					if (board[r + i][c + j] == 1 && stiky[i][j] == 1)
					{
						flag = false;
						break;
					}
				}
			}
			if (!flag)
				continue;
			// (r,c) ~ (r+i-1, c+j-1)에 스티커를 붙일 수 있다.
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if (stiky[i][j] == 1)
						board[r + i][c + j] = 1;
				}
			}
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < K; i++)
	{
		cin >> R >> C;
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C : c++)
				cin >> paper[r][c];

		if (check()) // 0
			continue;
		rotate();
		if (check()) // 90
			continue;
		rotate();
		if (check()) // 180
			continue;
		rotate();
		if (check()) // 270
			continue;
	}

	int cnt = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cnt += board[r][c];
	cout << cnt << '\n';
}