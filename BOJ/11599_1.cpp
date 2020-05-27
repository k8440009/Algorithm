// Puyo Puyo 1회차 : 40분
// https://www.acmicpc.net/problem/11559
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,-1,0,1 };
char board[12][6];
int answer = 0;

void move_puyo()
{
	for (int c = 0; c < 6; c++)
	{
		queue <char> q;
		for (int r = 11; r >= 0; r--)
		{
			if (board[r][c] != '.')
			{
				q.push(board[r][c]);
				board[r][c] = '.';
			}
		}
		int r = 11;
		while (!q.empty())
		{
			char data = q.front();
			q.pop();

			board[r][c] = data;
			r--;
		}
	}
}

bool solve()
{
	bool flag = true;
	for (int r = 0; r < 12; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			if (board[r][c] != '.')
			{
				char base = board[r][c];
				bool visited[12][6];
				vector <pair<int, int>> loc;
				queue <pair<int, int>> q;

				fill_n(visited[0], 12 * 6, 0);
				q.push(make_pair(r, c));
				loc.push_back(make_pair(r, c));
				visited[r][c] = true;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nr = cur.first + dr[dir], nc = cur.second + dc[dir];

						if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6)
							continue;
						else if (board[nr][nc] != base || visited[nr][nc])
							continue;

						q.push(make_pair(nr, nc));
						loc.push_back(make_pair(nr, nc));
						visited[nr][nc] = true;
					}
				}
				if (loc.size() >= 4)
				{
					for (int i = 0; i < loc.size(); i++)
					{
						int r = loc[i].first, c = loc[i].second;
						board[r][c] = '.';
					}
					flag = false;
				}
			}
		}
	}
	move_puyo();
	if (!flag)
		answer += 1;
	return flag;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int r = 0; r < 12; r++)
		for (int c = 0; c < 6; c++)
			cin >> board[r][c];

	while (1)
	{
		if (solve())
			break;
	}
	cout << answer << '\n';
}