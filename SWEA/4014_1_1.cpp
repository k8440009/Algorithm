// 4014. [모의 SW 역량테스트] 활주로 건설
#include <iostream>
using namespace std;

int bridge[22][22];
int answer = 0;
int N, X;

void print_board(int name[22][22])
{
	cout << '\n';
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << name[r][c] << ' ';
		}
		cout << '\n';
	}
}

void copy_board(int desc[22][22], int src[22][22])
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			desc[r][c] = src[r][c];
}

void solve(int board[22][22])
{
	fill_n(bridge[0], 22 * 22, 0);

	for (int r = 0; r < N; r++)
	{
		bool flag = 1;
		int c = 0;
		while (c < N - 1)
		{
			if (board[r][c] != board[r][c + 1])
			{
				if (board[r][c] < board[r][c + 1])
				{
					int start = c + 1 - X;
					if (start < 0 || ((board[r][c] + 1) != board[r][c + 1]))
					{
						flag = 0;
						break;
					}
					else
					{
						int base = board[r][start];
						for (int i = start; i < start + X; i++)
						{
							if (base != board[r][i] || bridge[r][i])
							{
								flag = 0;
								break;
							}
							bridge[r][i] = 1;
						}
						if (flag)
							c = start + X - 1;
					}
				}
				else
				{
					int end = c + X;
					if (end >= N || ((board[r][c]) != (board[r][c + 1] + 1)))
					{
						flag = 0;
						break;
					}
					else
					{
						int base = board[r][c + 1];
						for (int i = c + 1; i <= end; i++)
						{
							if (base != board[r][i] || bridge[r][i])
							{
								flag = 0;
								break;
							}
							bridge[r][i] = 1;
						}
						if (flag)
							c = end - 1;
					}
				}
			}
			if (!flag)
				break;
			c++;
		}
		if (flag)
			answer++;
	}
}

void rotate(int board[22][22])
{
	int tmp[22][22];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			tmp[c][N - 1 - r] = board[r][c];
	copy_board(board, tmp);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		int board[22][22], rotate_board[22][22];
		answer = 0;
		cin >> N >> X;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> board[r][c];

		int s_r = 0;
		for (int c = 0; c < N; c++)
		{
			for (int r = N - 1; r >= 0; r--)
			{
				rotate_board[s_r++][c] = board[r][c];
			}
			s_r = 0;
		}
		solve(board);
		rotate(rotate_board);
		solve(rotate_board);
		cout << "#" << ts << ' ' << answer << '\n';
	}
}