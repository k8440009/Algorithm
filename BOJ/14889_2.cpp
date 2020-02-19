// 스타트와 링크
// https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 20 + 1;

int answer = INF;
int N;
int board[MAX][MAX];
int visited[MAX];

void dfs(int curr, int cnt)
{
	if (curr > N)
		return;

	if (cnt == N / 2)
	{
		vector<int> a_team, b_team;
		// 연산
		for (int i = 0; i < N; i++)
		{
			if (visited[i])
				a_team.push_back(i);
			else
				b_team.push_back(i);
		}

		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = i + 1; j < N / 2; j++)
			{

				sum_a += (board[a_team[i]][a_team[j]] + board[a_team[j]][a_team[i]]);
				sum_b += (board[b_team[i]][b_team[j]] + board[b_team[j]][b_team[i]]);
			}
		}

		int sum = abs(sum_a - sum_b);
		if (answer > sum)
			answer = sum;
		return;
	}

	visited[curr] = 1;
	dfs(curr + 1, cnt + 1);
	visited[curr] = 0;
	dfs(curr + 1, cnt);
}

void print()
{
	cout << answer;
}
void solve()
{
	dfs(0, 0);
}
void init()
{
	cin >> N;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();
	print();
}