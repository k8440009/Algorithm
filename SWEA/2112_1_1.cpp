// 2112. [모의 SW 역량테스트] 보호 필름, 여러개 dfs(조합)
#include <iostream>
using namespace std;

int D, W, K;
int answer;

void copy_board(int desc[15][22], int src[15][22])
{
	for (int r = 0; r < D; r++)
		for (int c = 0; c < W; c++)
			desc[r][c] = src[r][c];
}

bool check(int board[15][22])
{
	for (int c = 0; c < W; c++)
	{
		bool flag = false;
		int r = 1, cnt = 1, base = board[0][c];

		while (r < D)
		{
			if (board[r][c] == base)
				cnt++;
			else
			{
				base = board[r][c];
				cnt = 1;
			}

			if (cnt == K)
			{
				flag = true;
				break;
			}
			r++;
		}
		if (!flag)
			return false;
	}
	return true;
}

void dfs(int cur, int cnt, int cur_board[15][22])
{

	if (cnt >= answer)
		return;
	if (check(cur_board))
	{
		answer = cnt;
		return;
	}
	if (cur == D)
		return;

	int next_board[15][22];
	copy_board(next_board, cur_board);
	dfs(cur + 1, cnt, next_board);
	// 0번 칠함
	for (int c = 0; c < W; c++)
		next_board[cur][c] = 0;
	dfs(cur + 1, cnt + 1, next_board);
	// 1번 칠함
	for (int c = 0; c < W; c++)
		next_board[cur][c] = 1;
	dfs(cur + 1, cnt + 1, next_board);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("sample_1.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		cin >> D >> W >> K;
		answer = 22;
		int board[15][22];
		for (int r = 0; r < D; r++)
			for (int c = 0; c < W; c++)
				cin >> board[r][c];
		if (K == 1)
			answer = 0;
		else
			dfs(0, 0, board);
		cout << "#" << ts << ' ' << answer << '\n';
	}
}

/*
	참고
	dfs 함수 여러개 : https://regularmember.tistory.com/120
	dfs + visited : https://yabmoons.tistory.com/219
*/