// 1번 - 스티커 붙이기 18808
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 40 + 1;

struct STIKY
{
	int r, c;
	int board[11][11];
};
int N, M, K;
int board[MAX][MAX];
vector<STIKY> stiky;

void board_copy(int desc, int src)
{
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			desc[r][c] = src[r][c];
}
int check(int tmp_board, int s_r, int s_c)
{
	int new_board[MAX][MAX];
	board_copy(new_board, board);
	for (int r = s_r; r < N; r++)
	{
		for (int c = s_c; c < M; c++)
		{
			if (new_board[r][c] == 1)
				return 0;
			else
				new_board[r][c] = tmp_board[r - s_r][c - s_c];
		}
	}
	board_copy(board, new_board);
	return 1;
}

void rotate(int desc, int src)
{
	for (int r = 0; r < 11; r++)
	{
		for (int c = 0; c < 11; c++)
		{
			desc[r][c] = src[11 - 1 - c][r];
		}
	}
}
void solve()
{
	// k개의 스티커를 붙여본다.
	for (int i = 0; i < K; i++)
	{
		int max_r = stiky[i].r;
		int max_c = stiky[i].c;
		int new_board[11][11];

		for (int r = 0; r < max_r; r++)
			for (int c = 0; c < max_c; c++)
				new_board[r][c] = stiky[i].board[r][c];

		int flag = 0;
		for (int dir = 0; dir < 4; dir++)
		{
			int tmp_board[11][11];
			if (flag == 1)
				break;
			// 0 ~ 270 보드 만들기
			if (dir == 1)
				rotate(tmp_board, new_board);
			else if (dir == 2)
				rotate(tmp_board, new_board);
			else if (dir == 3)
				rotate(tmp_board, new_board);

			// 계산
			for (int r = 0; r <= N - max_r; r++)
			{
				for (int c = 0; c <= M - max_c; c++)
				{
					if (check(new_board, r, c))
					{
						flag = 1;
						break;
					}
				}
			}
		}

		// for문으로 가장 왼쪽에서 부터 오른쪽까지 실행 (사이즈에 맞게)
		// 붙이기, 안되면 회전해서라도 붙이기
	}
	// board에서 채워진 갯수 세기
}
void init()
{
	cin >> N >> M >> K;
	// 스티커
	stiky.resize(K);
	for (int i = 0; i < K; i++)
	{
		int R, C;
		cin >> R >> C;
		stiky[i].r = R, stiky[i].c = C;
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				cin >> stiky[i].board[r][c];
	}

	cout << '\n';
	for (int i = 0; i < K; i++)
	{
		for (int r = 0; r < stiky[i].r; r++)
		{
			for (int c = 0; c < stiky[i].c; c++)
			{
				cout << stiky[i].board[r][c] << ' ';
			}
			cout << '\n';
		}
	}
	cout << '\n';
}

void solve2()
{
	int max_r = 2, max_c = 5;
	cout << '\n';
	for (int r = 0; r < max_r; r++)
	{
		for (int c = 0; c < max_c; c++)
		{
			cout << tmp_board[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	max_r = 2, max_c = 5;
	for (int r = 0; r < 11; r++)
	{
		for (int c = 0; c < 11; c++)
		{
			new_board[r][c] = tmp_board[11 - 1 - c][r];
		}
	}

	cout << "90" << '\n';
	for (int r = 0; r < 11; r++)
	{
		for (int c = 0; c < 11; c++)
		{
			cout << new_board[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//init();
	//solve();

	solve2();
}