// 연구소
// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 8 + 1;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

int N, M, answer;
int board[MAX][MAX];
vector<pair<int, int>> blank;

void print()
{
	printf("%d\n", answer);
}
void simulation()
{
	int test_board[MAX][MAX];
	bool visited[MAX][MAX];
	queue<pair<int, int>> q;

	fill_n(visited[0], MAX * MAX, 0);

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			test_board[r][c] = board[r][c];
			if (board[r][c] == 2)
			{
				q.push(make_pair(r, c));
				visited[r][c] = 1;
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.first + dr[dir];
			int nc = cur.second + dc[dir];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				continue;
			if (!visited[nr][nc] && test_board[nr][nc] == 0)
			{
				visited[nr][nc] = 1;
				test_board[nr][nc] = 2;
				q.push(make_pair(nr, nc));
			}
		}
	}

	int safe = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (test_board[r][c] == 0)
				safe++;
		}
	}
	if (safe >= answer)
		answer = safe;
}
void dfs(int curr, int cnt)
{
	if (cnt == 3)
	{
		simulation();
		return;
	}

	if (curr == blank.size())
		return;

	int row = blank[curr].first, col = blank[curr].second;
	board[row][col] = 1;
	dfs(curr + 1, cnt + 1);
	board[row][col] = 0;
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
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 0)
				blank.push_back(make_pair(r, c));
		}
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