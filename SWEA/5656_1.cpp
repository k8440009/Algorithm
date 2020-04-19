// 5656. [모의 SW 역량테스트] 벽돌 깨기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
int answer;
int N, W, H;
int board[17][14];

void copy_board(int desc[17][14], int src[17][14])
{
	for (int r = 0; r < H; r++)
		for (int c = 0; c < W; c++)
			desc[r][c] = src[r][c];
}

void distory(int s_r, int s_c, int test_board[17][14])
{
	int cnt = test_board[s_r][s_c];
	test_board[s_r][s_c] = 0;
	for (int dir = 0; dir < 4; dir++)
	{
		int r = s_r, c = s_c;
		for (int block = cnt - 1; block > 0; block--)
		{
			int nr = r + dr[dir];
			int nc = c + dc[dir];

			if (nr < 0 or nr >= H or nc < 0 or nc >= W)
				break;
			if (test_board[nr][nc] > 1)
				distory(nr, nc, test_board);
			test_board[nr][nc] = 0;
			r = nr, c = nc;
		}
	}
}

void next_board(int test_board[17][14])
{
	queue<int> q;
	for (int c = 0; c < W; c++)
	{
		for (int r = H - 1; r >= 0; r--)
		{
			if (test_board[r][c] > 0)
				q.push(test_board[r][c]);
		}
		int r = H - 1;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			test_board[r][c] = cur;
			r -= 1;
		}
		while (r >= 0)
		{
			test_board[r][c] = 0;
			r -= 1;
		}
	}
}

void simulate(int pos, int test_board[17][14])
{
	for (int i = 0; i < H; i++)
	{
		if (test_board[i][pos] > 0)
		{
			distory(i, pos, test_board);
			next_board(test_board);
			break;
		}
	}
}

void dfs(int cnt, int test_board[17][14])
{
	if (cnt == N)
	{
		int total = 0;
		for (int r = 0; r < H; r++)
			for (int c = 0; c < W; c++)
				if (test_board[r][c] > 0)
					total += 1;
		answer = min(answer, total);
		return;
	}

	for (int i = 0; i < W; i++)
	{
		int tmp[17][14];

		copy_board(tmp, test_board);
		simulate(i, tmp);
		dfs(cnt + 1, tmp);
	}
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
		int test_board[17][14];
		answer = 987654321;

		cin >> N >> W >> H;
		for (int r = 0; r < H; r++)
			for (int c = 0; c < W; c++)
				cin >> board[r][c];
		copy_board(test_board, board);
		dfs(0, test_board);
		cout << "#" << ts << ' ' << answer << '\n';
	}
}