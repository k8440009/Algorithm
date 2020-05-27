// 경사로 3회차 : 40분
#include <iostream>
#include <vector>
using namespace std;

int N, L;
int board[101][101];
int visited[101][101];

void rotate()
{
	int tmp[101][101];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			tmp[r][c] = board[r][c];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			board[r][c] = tmp[N - 1 - c][r];
}

bool solve(int s_r, int s_c)
{
	int r = s_r;
	int height = board[s_r][s_c];

	for (int c = s_c + 1; c < N; c++)
	{
		if (board[r][c] == height)
			continue;
		else if (board[r][c] ==  height + 1)
		{
			// 범위
			if (c - L < 0)
				return false;
			// 높이, 이전 방문 체크
			for (int prev = c - 1; prev >= c - L; prev--)
			{
				if (board[r][prev] != height || visited[r][prev])
					return false;
			}
			for (int prev = c - 1; prev >= c - L; prev--)
				visited[r][prev] = 1;
			height = board[r][c];
		}
		else if (board[r][c] == height - 1)
		{
			if (c + L - 1 >= N)
				return false;
			for (int next = c; next < c + L; next++)
			{
				if (board[r][next] != height - 1 || visited[r][next])
					return false;
			}
			for (int next = c; next < c + L; next++)
				visited[r][next] = 1;
			height = board[r][c];
		}
		else
			return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int answer = 0;
	cin >> N >> L;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
	for (int r = 0; r < N; r++)
		if (solve(r, 0))
			answer += 1;
	rotate();
	fill_n(visited[0], 101 * 101, 0);
	for (int r = 0; r < N; r++)
		if (solve(r, 0))
			answer += 1;
	cout << answer << '\n';
}