// 다리 만들기 2 1회차 : 180분
// https://www.acmicpc.net/problem/17472
#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };

struct BRIDGE
{
	int st, end, len;
};

int N, M, answer, city_total;
int board[11][11], visited[11][11];
bool selected[111];
vector <BRIDGE> bridge;

int find_land()
{
	int cnt = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (board[r][c] == 1 && visited[r][c] == 0)
			{
				cnt += 1;
				queue <pair<int, int>> q;
				q.push(make_pair(r, c));
				visited[r][c] = cnt;
				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M)
							continue;
						else if (board[nr][nc] == 0 || visited[nr][nc] > 0)
							continue;

						q.push(make_pair(nr, nc));
						visited[nr][nc] = cnt;
					}
				}
			}
		}
	}
	return cnt;
}

void get_dist(int city)
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (visited[r][c] == city)
			{
				int nr = r, nc = c;
				for (int dir = 0; dir < 4; dir++)
				{
					int size = 0;
					while (true)
					{
						nr += dr[dir], nc += dc[dir];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] == city)
							break;
						// 섬 만남
						if (visited[nr][nc])
						{
							if (size >= 2)
							{
								bool flag = false;
								for (int i = 0; i < bridge.size(); i++)
								{
									if (bridge[i].st == city && bridge[i].end == visited[nr][nc])
									{
										if (bridge[i].len > size)
											bridge[i].len = size;
										flag = true;
									}
								}
								if (!flag)
								{
									BRIDGE tmp;
									tmp.st = city, tmp.end = visited[nr][nc], tmp.len = size;
									bridge.push_back(tmp);
								}
							}
							break;
						}
						size += 1;
					}
				}
			}
		}
	}
}

bool is_connected()
{
	queue <int> q;
	bool used[11], check[11][11];

	fill_n(used, 11, 0), fill_n(check[0], 11 * 11, 0);
	for (int i = 0; i < bridge.size(); i++)
	{
		if (selected[i])
		{
			check[bridge[i].st][bridge[i].end] = 1;
			check[bridge[i].end][bridge[i].st] = 1;
		}
	}

	q.push(1);
	used[1] = 1;
	int cnt = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= city_total; i++)
		{
			if (!used[i] && check[cur][i])
			{
				used[i] = 1;
				q.push(i);
				cnt += 1;
			}
		}
	}
	if (cnt == city_total)
		return true;
	return false;
}

void dfs(int cnt, int prev, int val)
{
	if (cnt == val)
	{
		if (is_connected())
		{
			int sum = 0;
			for (int i = 0; i < bridge.size(); i++)
			{
				if (selected[i])
					sum += bridge[i].len;
			}
			answer = min(answer, sum);
		}
		return;
	}

	for (int i = 0; i < bridge.size(); i++)
	{
		if (selected[i] || prev > i)
			continue;

		selected[i] = true;
		dfs(cnt + 1, i, val);
		selected[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	answer = INF;
	cin >> N >> M;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> board[r][c];

	city_total = find_land();
	for(int i = 1; i <= city_total; i++)
		get_dist(i);
	dfs(0, 0, city_total - 1);
	if (answer == INF)
		answer = -1;
	cout << answer << '\n';
}