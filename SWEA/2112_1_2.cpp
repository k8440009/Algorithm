// 2112. [모의 SW 역량테스트] 보호 필름, select + dfs(조합)
#include <iostream>
#include <algorithm>
using namespace std;

int D, W, K;
int answer;

bool selected[22];
int board[15][22], cur_board[15][22];

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

void make_visited(int idx, int value, bool state)
{
	if (state == true)
	{
		for (int c = 0; c < W; c++)
			cur_board[idx][c] = value;
	}
	else
	{
		for (int c = 0; c < W; c++)
			cur_board[idx][c] = board[idx][c];
	}
}

void dfs(int cur, int cnt)
{
	if (cnt > K || cnt >= answer)
		return;
	if (check(cur_board))
	{
		answer = min(answer, cnt);
		return;
	}

	for (int i = cur; i < D; i++)
	{
		if (selected[i])
			continue;
		selected[i] = true;
		for (int j = 0; j < 2; j++)
		{
			make_visited(i, j, true);
			dfs(i, cnt + 1);
			make_visited(i, j, false);
		}
		selected[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample_1.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		cin >> D >> W >> K;
		answer = K;
		for (int r = 0; r < D; r++)
			for (int c = 0; c < W; c++)
			{
				cin >> board[r][c];
				cur_board[r][c] = board[r][c];
			}
		if (K == 1 || check(cur_board))
			answer = 0;
		else
			dfs(0, 0);
		cout << "#" << ts << ' ' << answer << '\n';
	}
}