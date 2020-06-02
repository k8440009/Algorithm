// 캐슬 디펜스 1회차 : 90분
// https://www.acmicpc.net/problem/17135
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct INFO
{
	int r, c, dist;
};

int N, M, D, answer;
int next_board[16][16];
bool selected[16];

int dist(int r1, int c1, int r2, int c2)
{
	int d = abs(r1 - r2) + abs(c1 - c2);
	if (d <= D)
		return d;
	else
		return 0;
}

void solve(int board[16][16])
{
	int total = 0;
	vector<pair<int, int>> archer;

	for (int i = 0; i < M; i++)
	{
		if (selected[i])
		{
			archer.push_back(make_pair(N, i));
		}
	}
	while (true)
	{
		vector<INFO> target;
		for (int i = 0; i < 3; i++)
		{
			INFO tmp;
			tmp.r = N, tmp.c = M, tmp.dist =  N * M;
			target.push_back(tmp);
		}
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				if (board[r][c] == 0)
					continue;
				for (int i = 0; i < archer.size(); i++)
				{
					int d = dist(archer[i].first, archer[i].second, r, c);
					if (d > 0)
					{
						// 처음
						if (target[i].r == N)
							target[i].r = r, target[i].c = c, target[i].dist = d;
						else
						{
							// 거리가 작을 때
							if (target[i].dist > d)
								target[i].r = r, target[i].c = c, target[i].dist = d;
							else if (target[i].dist == d)
							{
								if (target[i].c > c)
									target[i].r = r, target[i].c = c;
							}
						}
					}
				}
			}
		}
		// 삭제
		for (int i = 0; i < 3; i++)
		{
			if (target[i].r == N)
				continue;
			int r = target[i].r, c = target[i].c;
			if (board[r][c] == 1)
			{
				total += 1;
				board[r][c] = 0;
			}
		}

		bool flag = false;
		for (int r = N - 1; r >= 0; r--)
		{
			for (int c = 0; c < M; c++)
			{
				if (board[r][c] == 1)
				{
					if (r + 1 == N)
						next_board[r][c] = 0;
					else
					{
						next_board[r + 1][c] = 1;
						flag = true;
					}
				}
			}
		}
		if (!flag)
		{
			answer = max(answer, total);
			return;
		}
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				board[r][c] = next_board[r][c];
				next_board[r][c] = 0;
			}
		}
	}
}

void dfs(int curr, int prev, int cnt, int board[16][16])
{
	if (cnt == 3)
	{
		int cur_board[16][16];
		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++)
				cur_board[r][c] = board[r][c];
		solve(cur_board);
		return;
	}

	for (int i = 0; i < M; i++)
	{
		if (selected[i] || prev > i)
			continue;
		selected[i] = 1;
		dfs(curr + 1, i, cnt + 1, board);
		selected[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	answer = 0;
	cin >> N >> M >> D;
	int board[16][16];
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> board[r][c];
	dfs(0,0,0, board);
	cout << answer << '\n';
}