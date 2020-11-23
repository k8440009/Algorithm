// 알파벳
// https://www.acmicpc.net/problem/1987
#include <iostream>
using namespace std;

const int MAX = 20 + 1;
const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};
char board[MAX][MAX];
int R, C, answer;

void dfs(int s_r, int s_c, int visited[MAX][MAX], bool used[256], int cnt)
{
	int flag = 0;
	for (int dir = 0; dir < 4; dir++)
	{
		int nr = s_r + dr[dir];
		int nc = s_c + dc[dir];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C 
		|| visited[nr][nc] || used[board[nr][nc]])
			flag++;
		else
			break;	
	}

	if (flag == 4)
	{
		answer = max(answer, cnt);
		return ;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		int nr = s_r + dr[dir];
		int nc = s_c + dc[dir];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C 
		|| visited[nr][nc] || used[board[nr][nc]])
			continue;
		
		visited[nr][nc] = 1;
		used[board[nr][nc]] = 1;
		dfs(nr, nc, visited, used, cnt + 1);
		visited[nr][nc] = 0;
		used[board[nr][nc]] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> board[r][c];

	int visited[MAX][MAX];
	bool used[256];
	fill_n(visited[0], MAX * MAX, 0);
	fill_n(used, 256, 0);

	visited[0][0] = 1;
	used[board[0][0]] = true;
	dfs(0, 0, visited, used, 1);
	cout << answer;
}
