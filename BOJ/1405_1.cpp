// 미친 로봇
// https://www.acmicpc.net/problem/1405
#include <iostream>
#include <iomanip>
using namespace std;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};
double answer;
double prob[4];
int N;


void dfs(int s_r, int s_c, bool visited[30][30], int cnt, double chance)
{
	if (cnt == N)
	{
		answer += chance;
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		int nr = s_r + dr[dir];
		int nc = s_c + dc[dir];
	
		if (visited[nr][nc])
			continue;

		visited[nr][nc] = 1;
		dfs(nr, nc, visited, cnt + 1, chance * prob[dir]);
		visited[nr][nc] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		cin >> prob[i];
		prob[i] *= 0.01;
	}
	
	bool visited[30][30];
	fill_n(visited[0], 30 * 30, 0);
	visited[14][14] = 1;
	dfs(14, 14, visited, 0, 1.0);
	cout << fixed;
	cout << setprecision(10) << answer << '\n';
}