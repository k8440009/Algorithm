// 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 50 + 1;
const int INF = 987654321;

struct POS
{
	int r, c;
};

int	N, M, answer = INF;
int	board[MAX][MAX];
vector <POS> house, chicken, pick;

int dist(int s_r, int s_c, int e_r, int e_c)
{
	return abs(s_r - e_r) + abs(s_c - e_c);
}

void dfs(int idx)
{
	if (pick.size() == M)
	{
		int candi = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int min_dist = INF;
			for (int j = 0; j < pick.size(); j++)
				min_dist = min(min_dist, dist(house[i].r, house[i].c, pick[j].r, pick[j].c));
			candi += min_dist;
		}
		answer = min(answer, candi);
		return ;
	}

	for (int i = idx; i < chicken.size(); i++)
	{
		pick.push_back(chicken[i]);
		dfs(i + 1);
		pick.pop_back();
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
			POS target;
			if (board[r][c] == 1)
			{
				target.r = r, target.c = c;
				house.push_back(target);
			}
			else if (board[r][c] == 2)
			{
				target.r = r, target.c = c;
				chicken.push_back(target);
			}
		}
	}
	dfs(0);
	cout << answer << '\n';
}