// 원판 돌리기 - 3회 120분
// https://www.acmicpc.net/problem/17822
#include <iostream>
using namespace std;

const int MAX = 50 + 2;
const int DEL = -1;
const int dr[] = { 1,-1,0,0 };
const int dc[] = { 0,0,1,-1 };

int N, M, T;
int board[MAX][MAX];

void solve(int s_c, int d, int k)
{
	int pick = s_c - 1;
	if (d == 1)
		k = -k;
	// 회전
	while (pick < N)
	{
		int temp[MAX];
		fill_n(temp, MAX, 0);

		for (int i = 0; i < M; i++)
			temp[(i + k + M) % M] = board[pick][i];
		for (int i = 0;  i < M; i++)
			board[pick][i] = temp[i];
		pick += s_c;
	}

	bool is_update = false;
	bool check[MAX][MAX];
	fill_n(check[0], MAX * MAX, 0);

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nr = r + dr[dir], nc = (c + dc[dir] + M) % M;
				if (nr < 0 || nr >= N)
					continue;
				if (board[r][c] != DEL && board[nr][nc] != DEL && board[r][c] == board[nr][nc])
				{
					is_update = true;
					check[r][c] = true;
					check[nr][nc] = true;
				}
			}
		}
	}

	if (is_update)
	{
		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++)
			{
				if (check[r][c] == true)
					board[r][c] = DEL;
			}
	}
	else
	{
		int sum = 0, count = 0;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				if (board[r][c] != DEL)
				{
					sum += board[r][c];
					++count;
				}
			}
		}

		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				if (board[r][c] != DEL)
				{
					if (board[r][c] * count > sum)
						--board[r][c];
					else if (board[r][c] * count < sum)
						++board[r][c];
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> board[r][c];
	
	for (int i = 0; i < T; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		solve(x, d, k);
	}
	int ret = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (board[r][c] != DEL)
				ret += board[r][c];
		}
	}
	cout << ret;
	return 0;
}

/*
**	참고자료
**	https://na982.tistory.com/124
*/