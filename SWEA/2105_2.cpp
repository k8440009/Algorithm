// 2105. [모의 SW 역량테스트] 디저트 카페 2회차 : 48분
#include <iostream>
#include <algorithm>
using namespace std;

int N, answer;
int board[21][21];

void solve(int s_r, int s_c, int d_1, int d_2)
{
	bool selected[101];
	fill_n(selected, 101, 0);
	
	int r = s_r, c = s_c, total = 0;
	for (int cnt_1 = 0; cnt_1 < d_1; cnt_1++)
	{
		int nr = r + 1, nc = c + 1;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			return;
		if (selected[board[nr][nc]])
			return;
		selected[board[nr][nc]] = 1;
		total += 1;
		r = nr, c = nc;
	}
	for (int cnt_2 = 0; cnt_2 < d_2; cnt_2++)
	{
		int nr = r + 1, nc = c - 1;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			return;
		if (selected[board[nr][nc]])
			return;
		selected[board[nr][nc]] = 1;
		total += 1;
		r = nr, c = nc;
	}
	for (int cnt_1 = 0; cnt_1 < d_1; cnt_1++)
	{
		int nr = r - 1, nc = c - 1;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			return;
		if (selected[board[nr][nc]])
			return;
		selected[board[nr][nc]] = 1;
		total += 1;
		r = nr, c = nc;
	}
	for (int cnt_2 = 0; cnt_2 < d_2; cnt_2++)
	{
		int nr = r - 1, nc = c + 1;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			return;
		if (selected[board[nr][nc]])
			return;
		selected[board[nr][nc]] = 1;
		total += 1;
		r = nr, c = nc;
	}
	answer = max(answer, total);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("sample1.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		answer = -1;
		cin >> N;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> board[r][c];
		for (int r = 0; r < N - 2; r++)
			for (int c = 1; c < N - 1; c++)
				for (int cnt_1 = 1; cnt_1 < N - 1; cnt_1++)
					for (int cnt_2 = 1; cnt_2 < N - 1; cnt_2++)
						solve(r, c, cnt_1, cnt_2);
		cout << "#" << ts << ' ' << answer << '\n';
	}
}