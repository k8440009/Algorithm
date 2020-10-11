// 2048 (easy) 2회차 refactoring
// https://www.acmicpc.net/problem/12100
#include <iostream>
#include <vector>
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

int get_max(int src[MAX][MAX])
{
	int candi = 0;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			candi = max(candi, src[r][c]);
	return candi;
}

void copy_board(int desc[MAX][MAX], int src[MAX][MAX])
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			desc[r][c] = src[r][c];
}

void rotate(int src[MAX][MAX])
{
	int tmp[MAX][MAX];

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			tmp[r][c] = src[r][c];

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			src[r][c] = tmp[N - 1 - c][r];
}

void game(int cur[MAX][MAX])
{
	int tmp[MAX][MAX];

	for (int c = 0; c < N; c++)
	{
		bool flag = false;
		int target = -1;
		for (int r = 0; r < N; r++)
		{
			if (cur[r][c] == 0)
				continue;
			
			if (flag == true && cur[r][c] == tmp[target][c])
				tmp[target][c] *= 2, flag = false;
			else
				tmp[++target][c] = cur[r][c], flag = true;
		}
		for (++target; target < N; target++)
			tmp[target][c] = 0;
	}
	copy_board(cur, tmp);
}

void dfs(int cur[MAX][MAX], int cnt)
{
	if (cnt == 5)
	{
		answer = max(answer, get_max(cur));
		//print_board(cur);
		return ;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		int next[MAX][MAX];

		copy_board(next, cur);
		game(next);
		dfs(next, cnt + 1);
		rotate(cur);
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