#define _CRT_SECURE_NO_WARNINGS
// 마법사 상어와 토네이도
// https://www.acmicpc.net/problem/20057
#include <iostream>
using namespace std;


const int MAX = 499 + 1;
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {-1, 0, 1, 0};
int N, answer;
int board[MAX][MAX];
int sandPercent[4][3][10] =
{
	{
		{-1,-1,-1,-2,1,1,1,2,0,0},
		{0,-1,1,0,0,-1,1,0,-2,-1},
		{7,10,1,2,7,10,1,2,5,0}
	},
	{
		{-1,-1,0,0,0,0,1,1,2,1},
		{-1,1,-2,-1,2,1,-1,1,0,0},
		{1,1,2,7,2,7,10,10,5,0}
	},
	{
		{-2,-1,-1,-1,2,1,1,1,0,0},
		{0,-1,0,1,0,-1,0,1,2,1},
		{2,1,7,10,2,1,7,10,5,0}
	},
	{
		{-2,-1,-1,0,0,0,0,1,1,-1},
		{0,-1,1,-2,-1,2,1,-1,1,0},
		{5,10,10,2,7,2,7,1,1,0}
	}
};

void moveSand(int s_r, int s_c, int s_d) {
	int startSand = board[s_r][s_c];
	int r = s_r, c = s_c;
	int sum = 0;

	board[s_r][s_c] = 0;
	for (int i = 0; i < 10; i++) {
		int nr, nc, percent;
		if (i < 9) {
			nr = r + sandPercent[s_d][0][i];
			nc = c + sandPercent[s_d][1][i];
			percent = sandPercent[s_d][2][i];

			int divSand = startSand * percent / 100;

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
				answer += divSand;
				sum += divSand;
			}
			else{
				board[nr][nc] += divSand;
				sum += divSand;
			}
		}
		else {
			nr = r + sandPercent[s_d][0][i];
			nc = c + sandPercent[s_d][1][i];

			int divSand = startSand - sum;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
				answer += divSand;
			}
			else {
				board[nr][nc] += divSand;
			}
		}
	}
}

void rotate(int s_r, int s_c) {
	int dir = 0;
	int r = s_r, c = s_c;
	int turn = 1;
	for (; turn < N; turn++) {
		int cnt = 0;
		int nr = r, nc = c;
		while (cnt != 2) {

			for (int des = 0; des < turn; des++) {
				nr = r + dr[dir];
				nc = c + dc[dir];
				moveSand(nr, nc, dir);
				r = nr;
				c = nc;
			}
			dir = (dir + 1) % 4;
			cnt++;
		}
	}

	int cnt = 0;
	int nr = r, nc = c;
	while (cnt != 1) {

		for (int des = 0; des < turn - 1; des++) {
			nr = r + dr[dir];
			nc = c + dc[dir];
			moveSand(nr, nc, dir);
			r = nr;
			c = nc;
		}
		dir = (dir + 1) % 4;
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];

	rotate(N / 2, N / 2);
	cout << answer;
}