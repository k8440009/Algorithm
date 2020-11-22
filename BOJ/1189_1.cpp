// 컴백홈
// https://www.acmicpc.net/problem/1189
#include <iostream>
using namespace std;

const int MAX = 5 + 1;
const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};
int R,C,K;
char board[MAX][MAX];
int visited[MAX][MAX];
int answer;

void dfs(int r, int c, int visited[MAX][MAX], int cnt)
{
	if (r == 0 && c == C-1)
	{
		if (cnt == K)
			answer++;
		return ;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C 
		|| visited[nr][nc] || board[nr][nc] == 'T')
			continue;
		
		visited[nr][nc] = 1;
		dfs(nr, nc, visited, cnt + 1);
		visited[nr][nc] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> R >> C >> K;
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cin >> board[r][c];

	int visited[MAX][MAX];
	fill_n(visited[0], MAX * MAX, 0);
	visited[R - 1][0] = 1;
	dfs(R - 1, 0, visited, 1);
	visited[R - 1][0] = 0;
	cout << answer;
}