// 인싸들의 가위바위보 (next_permutation) 1회차 : 3시간
// https://www.acmicpc.net/problem/16986
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, answer;
int board[10][10];

vector <int> ji, ky, min_hu;

void solve(int player_1, int player_2, int index_s[3], int win_s[3])
{
	if (answer == 1 || index_s[0] == N || index_s[1] == 20 || index_s[1] == 20)
		return;

	if (player_1 == 0)
	{
		if (player_2 == 1)
		{
			int one = ji[index_s[0]], two = ky[index_s[1]];
			if (board[one][two] == 2)
			{
				index_s[0] += 1, index_s[1] += 1, win_s[0] += 1;
				if (win_s[0] == K)
				{
					answer = 1;
					return;
				}
				solve(0, 2, index_s, win_s);
			}
			else
			{
				index_s[0] += 1, index_s[1] += 1, win_s[1] += 1;
				if (win_s[1] == K)
					return;
				solve(1, 2, index_s, win_s);
			}
		}
		else if (player_2 == 2)
		{
			int one = ji[index_s[0]], two = min_hu[index_s[2]];
			if (board[one][two] == 2)
			{
				index_s[0] += 1, index_s[2] += 1, win_s[0] += 1;
				if (win_s[0] == K)
				{
					answer = 1;
					return;
				}
				solve(0, 1, index_s, win_s);
			}
			else
			{
				index_s[0] += 1, index_s[2] += 1, win_s[2] += 1;
				if (win_s[2] == K)
					return;
				solve(1, 2, index_s, win_s);
			}
		}
	}
	else
	{
		int one = ky[index_s[1]], two = min_hu[index_s[2]];
		if (board[one][two] == 2)
		{
			index_s[1] += 1, index_s[2] += 1, win_s[1] += 1;
			if (win_s[1] == K)
				return;
			solve(0, 1, index_s, win_s);
		}
		else
		{
			index_s[1] += 1, index_s[2] += 1, win_s[2] += 1;
			if (win_s[2] == K)
				return;
			solve(0, 2, index_s, win_s);
		}
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
	ky.resize(20), min_hu.resize(20);
	for (int i = 0; i < 20; i++)
		cin >> ky[i];
	for (int i = 0; i < 20; i++)
		cin >> min_hu[i];
	for (int i = 1; i <= N; i++)
		ji.push_back(i);

	do
	{
		int index_s[3] = { 0,0,0 }, win_s[3] = { 0,0,0 };
		solve(0,1, index_s, win_s);
	} while (next_permutation(ji.begin(), ji.end()));
	cout << answer << '\n';
}