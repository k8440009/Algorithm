// 인구 이동
// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50 + 1;
const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};

int N, L, R;
int board[MAX][MAX];
int visited[MAX][MAX];
vector<vector<pair<int, int>>> alias;

int g_flag;

void move_people()
{
	for (int i = 0; i < alias.size(); i++)
	{
		int total_people = 0;
		int cnt = alias[i].size();
		for (int j = 0; j < alias[i].size(); j++)
		{
			int r = alias[i][j].first, c = alias[i][j].second;
			total_people += board[r][c];
		}
		int move_people = total_people / cnt;
		for (int j = 0; j < alias[i].size(); j++)
		{
			int r = alias[i][j].first, c = alias[i][j].second;
			board[r][c] = move_people;
		}
	}
}

void bfs(int r, int c)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> mass;
	q.push(make_pair(r, c));
	visited[r][c] = 1;
	mass.push_back(make_pair(r, c));

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.first + dr[dir];
			int nc = cur.second + dc[dir];
			int people = board[cur.first][cur.second];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
				continue;
			if (abs(people - board[nr][nc]) >= L && abs(people - board[nr][nc]) <= R)
			{
				q.push(make_pair(nr, nc));
				visited[nr][nc] = 1;
				mass.push_back(make_pair(nr, nc));
				g_flag = 1;
			}
		}
	}
	alias.push_back(mass);
}
void solve()
{
	int cnt = 0;
	while (1)
	{
		fill_n(visited[0], MAX * MAX, 0);
		g_flag = 0;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (!visited[r][c])
					bfs(r, c);
			}
		}
		if (!g_flag)
			break;
		else
		{
			move_people();
			alias.clear();
			cnt++;
		}
	}
	cout << cnt << '\n';
}
void init()
{
	cin >> N >> L >> R;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();
}