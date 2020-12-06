// 마법사 상어와 토네이도
// https://www.acmicpc.net/problem/20057
#include <iostream>
using namespace std;

const int MAX = 499 + 1;
const int dr[] = {0,1,0,-1};
const int dc[] = {-1,0,1,0};
int N;
int board[MAX][MAX], tmpBoard[MAX][MAX];
int answer;

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

void moveSands(int s_r, int s_c, int dir, int totalSand){

	board[s_r][s_c] = 0;
	int sum = 0;
	for (int i = 0; i < 10; i++){
		int nr = s_r + sandPercent[dir][0][i];
		int nc = s_c + sandPercent[dir][1][i];

		if (i == 9){
			if (nr < 0 || nr >= N || nc < 0 || nc >= N)
				answer += (totalSand - sum);
			else
				board[nr][nc] += (totalSand - sum);
		}
		else
		{
			int per = sandPercent[dir][2][i];
			int moveSand = (totalSand * per) / 100;

			if (nr < 0 || nr >= N || nc < 0 || nc >= N){
				answer += moveSand;
				sum += moveSand;
				continue;
			}
			else{
				board[nr][nc] += moveSand;
				sum += moveSand;
			}
		}
	}
}

void circle(int st_r, int st_c){

	int dir = 0;
	int r = st_r, c = st_c;
	int turn = 1;
	for (; turn < N; turn++){
		int cnt = 0;
		while (cnt != 2)
		{
			int move = 0;
			while (move != turn)
			{
				// 다음 방향
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N)
					break;
				moveSands(nr, nc, dir, board[nr][nc]);
				r = nr, c = nc;
				move++;
			}
			dir = (dir + 1) % 4;
			cnt++;
		}
		cnt = 0;
	}


	int cnt = 0;
	while (cnt != 1)
	{
		int move = 0;
		while (move != turn)
		{
			// 다음 방향
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N)
				break;
			moveSands(nr, nc, dir, board[nr][nc]);
			r = nr, c = nc;
			move++;
		}
		dir = (dir + 1) % 4;
		cnt++;
	}
	cnt = 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
	circle(N / 2, N / 2);
	cout << answer;
}