// 인구이동 2회차 : 180분
// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dr[4] = { -1,1,0,0 };
const int dc[4] = { 0,0,-1,1 };
int N, L, R, answer = 0;
int board[52][52];

void print_board(int desc[52][52])
{
	cout << answer << '\n';
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			cout << desc[r][c] << ' ';
		}
		cout << '\n';
	}
}
bool solve()
{
	bool flag = false;
	bool visited[52][52];
	fill_n(visited[0], 52 * 52, 0);

	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if(visited[r][c])
				continue;

			int total = board[r][c];
			queue <pair<int, int>> q;
			vector<pair<int, int>> alias;
			q.push(make_pair(r, c));
			alias.push_back(make_pair(r, c));
			visited[r][c] = 1;

			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
					if (nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1 || visited[nr][nc])
						continue;
					int people = abs(board[nr][nc] - board[cur.first][cur.second]);
					if (people >= L && people <= R)
					{
						q.push(make_pair(nr, nc));
						alias.push_back(make_pair(nr, nc));
						visited[nr][nc] = 1;
						total += board[nr][nc];
					}
				}
			}

			if (alias.size() > 1)
			{
				flag = true;
				int divided = total / alias.size();
				for (int i = 0; i < alias.size(); i++)
					board[alias[i].first][alias[i].second] = divided;
			}
		}
	}
	return flag;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			cin >> board[r][c];

	while (true)
	{
		if (!solve())
			break;
		else
			answer += 1;
	}
	cout << answer << '\n';
}