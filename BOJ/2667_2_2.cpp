// 단지번호 붙이기
// https://www.acmicpc.net/problem/2667
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 25 + 1;
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N;
int apart;
int board[MAX][MAX];
int visited[MAX][MAX];

vector<int> answer;

void print()
{
	sort(answer.begin(), answer.end());
	cout << apart << '\n';
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';
}

void bfs(int row, int col)
{
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = 1;
	int cnt = 1;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.first + dr[dir];
			int nc = cur.second + dc[dir];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N)
				continue;

			if (board[nr][nc] == 1 && !visited[nr][nc])
			{
				visited[nr][nc] = 1;
				q.push(make_pair(nr, nc));
				cnt += 1;
			}
		}
	}

	answer.push_back(cnt);
	return;
}

void solve()
{
	apart = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (board[r][c] == 1 && !visited[r][c])
			{
				bfs(r, c);
				apart += 1;
			}
		}
	}
}

void init()
{
	cin >> N;
	for (int r = 0; r < N; r++)
	{
		string str;
		cin >> str;
		for (int c = 0; c < N; c++)
			board[r][c] = str[c] - '0';
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