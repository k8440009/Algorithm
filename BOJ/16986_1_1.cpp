// 인싸들의 가위바위보 (백트래킹) 1회차 : 3시간
// https://www.acmicpc.net/problem/16986
#include <iostream>
#include <vector>
using namespace std;

int N, K, answer;
int board[10][10];
int selected[11];
vector <int> ky, min_ho;

void solve(int player_1, int player_2, int ky_idx, int min_idx, int ji_win, int ky_win, int min_win)
{
	if (ji_win == K)
	{
		answer = 1;
		return;
	}
	else if (ky_win == K || min_win == K || answer == 1 || ky_idx == 20 || min_idx == 20)
		return;

	if (player_1 == 0)
	{
		if (player_2 == 1)
		{
			for (int i = 1; i <= N; i++)
			{
				if (selected[i])
					continue;
				int data = ky[ky_idx];
				selected[i] = 1;
				if (board[i][data] == 2)
					solve(0, 2, ky_idx + 1, min_idx, ji_win + 1, ky_win, min_win);
				else
					solve(1, 2, ky_idx + 1, min_idx, ji_win, ky_win + 1, min_win);
				selected[i] = 0;
			}
		}
		else if (player_2 == 2)
		{
			for (int i = 1; i <= N; i++)
			{
				if (selected[i])
					continue;
				int data = min_ho[min_idx];
				selected[i] = 1;
				if (board[i][data] == 2)
					solve(0, 1, ky_idx, min_idx + 1, ji_win + 1, ky_win, min_win);
				else
					solve(1, 2, ky_idx, min_idx + 1, ji_win, ky_win, min_win + 1);
				selected[i] = 0;
			}
		}
	}
	else
	{
		int data_1 = ky[ky_idx], data_2 = min_ho[min_idx];
		if(board[data_1][data_2] == 2)
			solve(0, 1, ky_idx + 1, min_idx + 1, ji_win, ky_win + 1, min_win);
		else
			solve(0, 2, ky_idx + 1, min_idx + 1, ji_win, ky_win, min_win + 1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	answer = 0;
	cin >> N >> K;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			cin >> board[r][c];
	ky.resize(20), min_ho.resize(20);
	for (int i = 0; i < 20; i++)
		cin >> ky[i];
	for (int i = 0; i < 20; i++)
		cin >> min_ho[i];
	solve(0, 1, 0, 0, 0, 0, 0);
	cout << answer << '\n';
}