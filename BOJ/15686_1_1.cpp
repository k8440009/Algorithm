// 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50 + 1;
const int INF = 987654321;
int N, M, answer = INF;
int board[MAX][MAX];
int visited[MAX];
vector<pair<int, int>> house, chicken;

void print()
{
	cout << answer << '\n';
}

void dfs(int curr, int cnt)
{
	if (cnt == M)
	{
		int total = 0;
		// 치킨 거리
		for (int i = 0; i < house.size(); i++)
		{
			int sum = INF;
			for (int j = 0; j < chicken.size(); j++)
			{
				if (visited[j])
					sum = min(sum, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
			}
			total += sum;
		}
		if (answer > total)
			answer = total;
		return;
	}

	if (curr == chicken.size())
		return;

	visited[curr] = 1;
	dfs(curr + 1, cnt + 1);
	visited[curr] = 0;
	dfs(curr + 1, cnt);
}
void solve()
{
	dfs(0, 0);
}
void init()
{
	cin >> N >> M;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 1)
				house.push_back(make_pair(r, c));
			else if (board[r][c] == 2)
				chicken.push_back(make_pair(r, c));
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