// 스티커 붙이기
// https://www.acmicpc.net/problem/18808
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[42][42];
int paper[12][12];
int N, M, K, R, C;

void rotate()
{
	int tmp[12][12];

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			tmp[r][c] = paper[r][c];

	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++)
			paper[i][j] = tmp[R - 1 - j][i];

	swap(R, C);
}

bool check()
{
	for (int r = 0; r <= N - R; r++)
	{
		for (int c = 0; c <= M - C; c++)
		{
			bool flag = true;
			for (int i = 0; i < R; i++)
			{
				if (!flag)
					break;
				for (int j = 0; j < C; j++)
				{
					if (board[r + i][c + j] == 1 && paper[i][j] == 1)
					{
						flag = false;
						break;
					}
				}
			}

			if (!flag)
				continue;

			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if (paper[i][j] == 1)
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

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> R >> C;

		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				cin >> paper[r][c];

		if (check())
			continue;
		rotate(); // 90;
		if (check())
			continue;
		rotate(); // 180;
		if (check())
			continue;
		rotate(); // 270
		if (check())
			continue;
	}

	int cnt = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (board[r][c] == 1)
				cnt++;
		}
	}

	cout << cnt << '\n';
}