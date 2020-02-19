// 톱니바퀴
// https://www.acmicpc.net/problem/14891
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
int gear[4][8];
vector<pair<int, int>> circle;

void print()
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		if (gear[i][0])
			sum += (1 << i);
	}
	cout << sum << '\n';
	/*
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << gear[i][j];
		cout << '\n';
	}
	*/
}
void move(int selected, int dir)
{

	if (dir == 1)
	{
		int temp = gear[selected][7];
		for (int i = 7; i - 1 >= 0; i--)
		{
			gear[selected][i] = gear[selected][i - 1];
		}
		gear[selected][0] = temp;
	}
	else
	{
		int temp = gear[selected][0];
		for (int i = 0; i + 1 < 8; i++)
		{
			gear[selected][i] = gear[selected][i + 1];
		}
		gear[selected][7] = temp;
	}
}
void solve()
{
	for (int i = 0; i < K; i++)
	{
		int check[4];
		fill_n(check, 4, 0);
		int selected = circle[i].first;
		if (selected == 0)
		{
			check[selected] = 1;
			for (int i = 0; i + 1 < 4; i++)
			{
				if (gear[i][2] != gear[i + 1][6])
					check[i + 1] = 1;
				else
					break;
			}
		}
		else if (selected == 1 || selected == 2)
		{
			check[selected] = 1;
			for (int i = selected; i - 1 >= 0; i--)
			{
				if (gear[i - 1][2] != gear[i][6])
					check[i - 1] = 1;
				else
					break;
			}
			for (int i = selected; i + 1 < 4; i++)
			{
				if (gear[i][2] != gear[i + 1][6])
					check[i + 1] = 1;
				else
					break;
			}
		}
		else if (selected == 3)
		{
			check[selected] = 1;
			for (int i = selected; i - 1 >= 0; i--)
			{
				if (gear[i - 1][2] != gear[i][6])
					check[i - 1] = 1;
				else
					break;
			}
		}

		int dir = circle[i].second;
		move(selected, dir);
		for (int j = selected; j + 1 < 4; j++)
		{
			if (check[j + 1])
			{
				dir *= (-1);
				move(j + 1, dir);
			}
			else
				break;
		}
		dir = circle[i].second;
		for (int j = selected; j - 1 >= 0; j--)
		{
			if (check[j - 1])
			{
				dir *= (-1);
				move(j - 1, dir);
			}
			else
				break;
		}
	}
}

void init()
{
	for (int i = 0; i < 4; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++)
			gear[i][j] = str[j] - '0';
	}
	cin >> K;
	circle.resize(K);
	for (int i = 0; i < K; i++)
	{

		int num, dir;
		cin >> num >> dir;
		num -= 1;
		circle[i].first = num, circle[i].second = dir;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();
	print();
}