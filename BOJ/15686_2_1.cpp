// 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 50 + 1;
const int INF = 987654321;
int	N, M, answer = INF;
int	board[MAX][MAX];
bool selcted[MAX];
vector <pair<int,int> > house, chicken;

int dist(int s_r, int s_c, int e_r, int e_c)
{
	return abs(s_r - e_r) + abs(s_c - e_c);
}

void dfs(int idx, int cnt)
{
	if (cnt == M)
	{
		int total = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int min_length = INF;
			for (int j = 0; j < chicken.size(); j++)
			{
				int tmp;
				if (selcted[j])
				{
					tmp = dist(house[i].first, house[i].second, chicken[j].first, chicken[j].second);
					min_length = min(min_length, tmp);
				}
			}
			total += min_length;
		}
		answer = min(answer, total);
		return ;
	}

	for (int i = idx; i < chicken.size(); i++)
	{
		
		if (selcted[i])
			continue;

		selcted[i] = true;
		dfs(i + 1, cnt + 1);
		selcted[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 1)
				house.push_back(make_pair(r,c));
			else if (board[r][c] == 2)
				chicken.push_back(make_pair(r,c));
		}
	}
	dfs(0, 0);
	cout << answer << '\n';
}