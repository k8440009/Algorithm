// 스타트와 링크
// https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20 + 1;
int N;
int board[MAX][MAX];
int visited[MAX];
int answer= 987654321;


void dfs(int idx, int cnt)
{
	if (idx == N)
		return;
	
	if (cnt == N / 2)
	{
		vector <int> team1, team2;
		for (int i = 0; i < N; i++)
		{
			if (visited[i])
				team1.push_back(i);
			else
				team2.push_back(i);
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < team1.size(); i++)
		{
			for (int j = i + 1; j < team1.size(); j++)
			{
				sum1 += board[team1[i]][team1[j]] + board[team1[j]][team1[i]];
				sum2 += board[team2[i]][team2[j]] + board[team2[j]][team2[i]];
			}
		}
		answer = min(answer, abs(sum1 - sum2));
		return ;
	}

	for (int i = idx; i < N; i++)
	{
		if (visited[i])
			continue;

		visited[i] = 1;
		dfs(i ,cnt + 1);
		visited[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
	dfs(0, 0);
	cout << answer;
}