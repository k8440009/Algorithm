// 모노미노도미노 (미완성)
// https://www.acmicpc.net/problem/19235
#include <iostream>
#include <queue>
using namespace std;

int N;
int board[10][10];
int ret;

void move(int type, int s_r, int s_c)
{
	// 초록
	if (type == 0)
	{
		for (int c = 0; c < 4; c++)
		{
			queue <int> q;
			for (int r = s_r - 1; r >= 4; r--)
			{
				if (board[r][c] != 0)
					q.push(board[r][c]);

			}

			int r = s_r;
			while (!q.empty())
			{
				board[r][c] = q.front();
				q.pop();
				r--;
			}
			for (r; r >= 4; r--)
				board[r][c] = 0;
		}
	}
	else if (type == 1)
	{
		for (int r = 0; r < 4; r++)
		{
			queue <int> q;
			for (int c = s_c - 1; c >= 4; c--)
			{
				if (board[r][c] != 0)
					q.push(board[r][c]);

			}

			int c = s_c;
			while (!q.empty())
			{
				board[r][c] = q.front();
				q.pop();
				r--;
			}
			for (c; c >= 4; c--)
				board[r][c] = 0;
		}
	}
}
void solve(int type, int s_r, int s_c)
{
	// 초록
	for (int r = 9; r >= 4; r--)
	{
		if (type == 1 && board[r][s_c] == 0)
		{
			board[r][s_c] = 1;
			break;
		}
		else if (type == 2 && (s_c + 1 < 4 && board[r][s_c] == 0 && board[r][s_c + 1] == 0))
		{
			board[r][s_c] = 1;
			board[r][s_c + 1] = 1;
			break;
		}
		else if (type == 3 && (r + 1 < 10 && board[r][s_c] == 0 && board[r + 1][s_c] == 0))
		{
			board[r][s_c] = 1;
			board[r + 1][s_c] = 1;
			break;
		}
	}
	// 파랑
	for (int c = 4; c + 1 < 10; c++)
	{
		if (type == 1 && board[s_r][c] == 1)
		{
			board[s_r][c - 1] = 1;
			break;
		}
		else if (type == 2 && (c + 1 < 10 && board[s_r][c] == 1 || board[s_r][c + 1] == 0))
		{
			board[s_r][c] = 1;
			board[s_r][c + 1] = 1;
			break;
		}
		else if (type == 3 && (s_r + 1 < 4 && board[s_r][c] == 0 && board[s_r + 1][c] == 0))
		{
			board[s_r][c] = 1;
			board[s_r + 1][c] = 1;
			break;
		}
	}
	// 제거
	int point = 0;
	bool is_point = false;
	while (true)
	{
		is_point = false;
		// 초록
		for (int r = 9; r >= 4; r--)
		{
			if (board[r][0] == 1 && board[r][1] == 1 && board[r][2] == 1 && board[r][3] == 1)
			{
				is_point = true;
				point++;
				board[r][0] = 0;
				board[r][1] = 0;
				board[r][2] = 0;
				board[r][3] = 0;
				// 빈칸 제거
				move(0, r, 0);
				break;
			}
		}
		// 파랑
		for (int c = 9; c >= 4; c--)
		{
			if (board[0][c] == 1 && board[1][c] == 1 && board[2][c] == 1 && board[3][c] == 1)
			{
				is_point = true;
				point++;
				board[0][c] = 1;
				board[1][c] = 1;
				board[2][c] = 1;
				board[3][c] = 1;
				// 빈칸 제거
				move(1, 0, c);
				break;
			}
		}

		if (!is_point)
			break;
	}
	ret += point;

	// 블록 밀기
	// 초록
	/*
	int check = 0;
	for (int r = 4; r < 6; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (board[r][c] == 1)
			{
				board[r][0] = 0;
				board[r][1] = 0;
				board[r][2] = 0;
				board[r][3] = 0;
				++check;
				break;
			}
		}
	}

	while (check)
	{
		for (int r = 9; r - 1 >= 4; r--)
			for (int c = 0; c < 4; c++)
				board[r][c] = board[r - 1][c];
		check--;
	}

	for (int c = 4; c < 6; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			if (board[r][c] == 1)
			{
				board[0][c] = 0;
				board[1][c] = 0;
				board[2][c] = 0;
				board[3][c] = 0;
				++check;
				break;
			}
		}
	}

	cout << "blue : " << check << '\n';
	while (check)
	{
		for (int c = 9; c - 1 >= 4; c--)
			for (int r = 0; r < 4; r++)
				board[r][c] = board[r][c - 1];
		check--;
	}
	*/
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	ret = 0;
	for (int i = 0; i < N; i++)
	{
		int t, r, c;
		cin >> t >> r >> c;
		solve(t, r, c);
	}

	int cnt = 0;
	for (int r = 4; r < 10; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (board[r][c] == 1)
				cnt++;
		}
	}

	for (int r = 0; r < 4; r++)
	{
		for (int c = 4; c < 10; c++)
		{
			if (board[r][c] == 1)
				cnt++;
		}
	}

	cout << "red\n";
	for (int r = 4; r < 10; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			cout << board[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "blue\n";
	for (int r = 0; r < 4; r++)
	{
		for (int c = 4; c < 10; c++)
		{
			cout << board[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << ret << '\n';
	cout << cnt;
}