// 외판원 순회 2
// https://www.acmicpc.net/problem/10971
#include <iostream>
using namespace std;

const int MAX = 10 + 1;
int N;
long long answer = 10987654321;
int board[MAX][MAX];

void dfs(int start, int cur, int visited[MAX], int cnt, long long total)
{

	if (total > answer)
		return ;

	if (cnt == N)
	{
		if (board[cur][start] != 0)
			answer = min(answer, total + board[cur][start]);
		return ;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (visited[i] || board[cur][i] == 0)
			continue;
		
		visited[i] = 1;
		dfs(start, i, visited, cnt + 1, total + board[cur][i]);
		visited[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> N;

	int visited[MAX];
	fill_n(visited, MAX, 0);
	for (int r = 0; r < N; r++)
		for(int c = 0; c < N; c++)
			cin >> board[r][c];
	
	for (int i = 0; i < N; i++)
	{
		visited[i] = 1;
		dfs(i, i, visited, 1, 0);
		visited[i] = 0;
	}
	cout << answer;
}