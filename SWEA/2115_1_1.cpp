// 2115. [모의 SW 역량테스트] 벌꿀채취
#include <iostream>
#include <vector>
using namespace std;

int answer, sum_a, sum_b;
int N, M, C;
int board[12][12];
int visited[12][12];
int selected[7];
vector<pair<int, int>> a, b;

void dfs(int cnt, int prev, int capacity, int usr)
{
	if (capacity > C)
		return;
	if (cnt == M)
	{
		if (usr == 0)
		{
			int total = 0;
			for (int i = 0; i < M; i++)
			{
				if (selected[i])
				{
					int data = board[a[i].first][a[i].second];
					total += (data * data);
				}
			}
			sum_a = max(sum_a, total);
		}
		else
		{
			int total = 0;
			for (int i = 0; i < M; i++)
			{
				if (selected[i])
				{
					int data = board[b[i].first][b[i].second];
					total += (data * data);
				}
			}
			sum_b = max(sum_b, total);
		}

		return;
	}

	for (int i = 0; i < M; i++)
	{
		if (selected[i])
			continue;
		if (prev > i)
			continue;

		selected[i] = 1;
		if (usr == 0)
			dfs(cnt + 1, i, capacity + board[a[i].first][a[i].second], usr);
		else
			dfs(cnt + 1, i, capacity + board[b[i].first][b[i].second], usr);
		selected[i] = 0;
	}
	dfs(cnt + 1, prev, capacity, usr);
}

void solve()
{
	sum_a = 0, sum_b = 0;
	dfs(0, 0, 0, 0);
	dfs(0, 0, 0, 1);
	answer = max(answer, sum_a + sum_b);
}

void pick(int s_r, int s_c)
{
	for (int r = s_r; r < N; r++)
	{
		for (int c = s_c; c < N; c++)
		{
			if (c + M > N)
				break;
			for (int j = c; j < c + M; j++)
			{
				b.push_back(make_pair(r, j));
				visited[r][j] = 1;
			}
			// 계산
			solve();
			for (int j = c; j < c + M; j++)
			{
				b.pop_back();
				visited[r][j] = 0;
			}
		}
		s_c = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		answer = 0;
		cin >> N >> M >> C;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> board[r][c];

		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (c + M <= N)
				{
					for (int j = c; j < c + M; j++)
					{
						a.push_back(make_pair(r, j));
						visited[r][j] = 1;
					}
					pick(r, c + M);
					for (int j = c; j < c + M; j++)
					{
						a.pop_back();
						visited[r][j] = 0;
					}
				}
			}
		}
		cout << "#" << ts << ' ' << answer << '\n';
	}
}