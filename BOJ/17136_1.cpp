// 색종이 붙이기 1회차 : 180분
// https://www.acmicpc.net/problem/17136
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int board[11][11], paper_cnt[6];
int answer = INF;

void update_paper(int r, int c, int size, int attach)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			board[r + i][c + j] = attach;
}
bool attach_paper(int r, int c, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[r + i][c + j] == 0)
				return false;
		}
	}
	return true;
}
void dfs(int r, int c, int attach)
{
	while (board[r][c] == 0)
	{
		if (++c >= 10)
		{
			if (++r >= 10)
			{
				answer = min(answer, attach);
				return;
			}
			c = 0;
		}
	}

	if (answer <= attach)
		return;

	for (int size = 5; size >= 1; size--)
	{
		if (r + size > 10 || c + size > 10 || paper_cnt[size] == 5)
			continue;
		if (attach_paper(r, c, size))
		{
			update_paper(r, c, size, 0);
			paper_cnt[size] += 1;
			dfs(r, c, attach + 1);
			update_paper(r, c, size, 1);
			paper_cnt[size] -= 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int total_cnt = 0;
	for (int r = 0; r < 10; r++)
		for (int c = 0; c < 10; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 1)
				total_cnt++;
		}

	if (total_cnt == 100)
		answer = 4;
	else
	{
		dfs(0, 0, 0);
		if (answer == INF)
			answer = -1;
	}
	cout << answer << '\n';
}