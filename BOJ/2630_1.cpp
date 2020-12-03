// 색종이 만들기
// https://www.acmicpc.net/problem/2630
#include <iostream>
using namespace std;

const int MAX = 128 + 1;
int N, white, blue;
int board[MAX][MAX];

void dfs(int s_r, int s_c, int size){
	int color = board[s_r][s_c];

	for (int r = s_r; r < s_r + size; r++){
		for (int c = s_c; c < s_c + size; c++){
			if (board[r][c] != color){
				int half = size / 2;
				dfs(s_r, s_c, half);
				dfs(s_r, s_c + half, half);
				dfs(s_r + half, s_c, half);
				dfs(s_r + half, s_c + half, half);
				return ;
			}
		}
	}

	if (color == 1)
		blue++;
	else
		white++;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
	dfs(0, 0, N);
	cout << white << '\n';
	cout << blue << '\n';
}