// 청소년 상어
// https://www.acmicpc.net/problem/19236
#include <iostream>
#include <algorithm>
using namespace std;

const int dr[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
const int dc[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };


struct FISH
{
	int r, c, d;
};

int answer;

void solve(int board[4][4], FISH fish[16], int shark_r, int shark_c, int sum)
{
	int next_board[4][4];
	FISH next_fish[16];

	for (int r = 0; r < 4; r++)
		for (int c = 0; c < 4; c++)
			next_board[r][c] = board[r][c];

	for (int i = 0; i < 16; i++)
		next_fish[i] = fish[i];

	// eat
	int fish_num = board[shark_r][shark_c];
	int shark_dir = next_fish[fish_num].d;
	next_fish[fish_num].r = -1;
	next_fish[fish_num].c = -1;
	next_fish[fish_num].d = -1;
	next_board[shark_r][shark_c] = -1;

	sum += (fish_num + 1);
	if (answer < sum)
		answer = sum;

	// fish move
	for (int i = 0; i < 16; i++)
	{
		if (next_fish[i].r == -1)
			continue;

		int cr = next_fish[i].r;
		int cc = next_fish[i].c;
		int cd = next_fish[i].d;

		int nr = cr + dr[cd];
		int nc = cc + dc[cd];
		int nd = cd;
		while (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || (nr == shark_r && nc == shark_c))
		{
			nd = (nd + 1) % 8;
			nr = cr + dr[nd];
			nc = cc + dc[nd];
		}

		if (next_board[nr][nc] != -1)
		{
			int target = next_board[nr][nc];

			next_fish[target].r = cr;
			next_fish[target].c = cc;
			next_fish[i].r = nr;
			next_fish[i].c = nc;
			next_fish[i].d = nd;

			next_board[nr][nc] = i;
			next_board[cr][cc] = target;
		}
		else
		{
			next_fish[i].r = nr;
			next_fish[i].c = nc;
			next_fish[i].c = nc;
			next_fish[i].d = nd;

			next_board[nr][nc] = i;
			next_board[cr][cc] = -1;
		}
	}
	// shark move
	for (int step = 1; step < 4; ++step)
	{
		int nr = shark_r + dr[shark_dir] * step;
		int nc = shark_c + dc[shark_dir] * step;

		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
			break;

		if (next_board[nr][nc] != -1)
			solve(next_board, next_fish, nr, nc, sum);
	}
}

int main()
{
	int board[4][4];
	FISH fish[16];

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			int a, b;
			cin >> a >> b;
			--a, --b;
			fish[a].r = r;
			fish[a].c = c;
			fish[a].d = b;
			board[r][c] = a;
		}
	}
	answer = 0;
	solve(board, fish, 0, 0, 0);
	cout << answer;
	return 0;
}

/*
**	참고자료
**	https://na982.tistory.com/127
*/