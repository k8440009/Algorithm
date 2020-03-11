// 주사위 굴리기
// https://www.acmicpc.net/problem/14499
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20 + 1;
const int dr[] = {0, 0, -1, 1};
const int dc[] = {1, -1, 0, 0};

int N, M, Y, X, K;
int board[MAX][MAX];
int dice[6];
vector<int> comd;

void print()
{
	cout << dice[0] << '\n';
}

void changeDice(int dir)
{
	// 동
	if (dir == 0)
	{
		int temp;

		temp = dice[2];

		dice[2] = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = temp;
	}
	// 서
	else if (dir == 1)
	{
		int temp;

		temp = dice[3];

		dice[3] = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = temp;
	}
	// 북
	else if (dir == 2)
	{
		int temp;

		temp = dice[1];

		dice[1] = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = temp;
	}
	// 남
	else
	{
		int temp;

		temp = dice[5];

		dice[5] = dice[4];
		dice[4] = dice[0];
		dice[0] = dice[1];
		dice[1] = temp;
	}
}
void solve()
{
	for (int i = 0; i < K; i++)
	{
		int dir = comd[i];
		int nr = Y + dr[dir];
		int nc = X + dc[dir];

		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
			continue;
		changeDice(dir);
		if (board[nr][nc] == 0)
			board[nr][nc] = dice[5];
		else
		{
			dice[5] = board[nr][nc];
			board[nr][nc] = 0;
		}
		print();
		Y = nr;
		X = nc;
	}
}

void init()
{
	cin >> N >> M >> Y >> X >> K;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
		}
	}
	comd.resize(K);
	for (int i = 0; i < K; i++)
	{
		cin >> comd[i];
		comd[i]--;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();
}