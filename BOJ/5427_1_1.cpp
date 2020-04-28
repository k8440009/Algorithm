// 불 메모리 초과 - 1600MB
// https://www.acmicpc.net/problem/5427
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int W, H;

char board[1000][1000];
bool visited[1000][1000];
vector<pair<int, int>> save_p, save_f;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("sample.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		int answer = 987654321;
		cin >> W >> H;
		fill_n(board[0], 1000 * 1000, '.');
		fill_n(visited[0], 1000 * 1000, 0);

		queue<pair<int, int>> fire, people;

		for (int r = 0; r < H; r++)
		{
			string tmp;
			cin >> tmp;
			for (int c = 0; c < W; c++)
			{
				board[r][c] = tmp[c];
				if (board[r][c] == '*')
					fire.push(make_pair(r, c));
				else if (board[r][c] == '@')
				{
					people.push(make_pair(r, c));
					visited[r][c] = 1;
					board[r][c] = '.';
				}
			}
		}

		int time = 0;
		bool flag = 1;
		while (flag)
		{
			save_p.clear(), save_f.clear();
			// 상근이가 움직인다.
			while (!people.empty())
			{
				pair<int, int> cur = people.front();
				people.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
					if (nr < 0 || nr >= H || nc < 0 || nc >= W)
					{
						if (answer > time + 1)
							answer = time + 1;
						flag = 0;
						break;
					}
					if (board[nr][nc] == '#' || board[nr][nc] == '*' || visited[nr][nc] == 1)
						continue;
					pair<int, int> next;
					next.first = nr, next.second = nc;
					save_p.push_back(next);
				}
			}
			if (!flag)
				break;
			while (!fire.empty())
			{
				pair<int, int> cur = fire.front();
				fire.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
					if (nr < 0 || nr >= H || nc < 0 || nc >= W)
						continue;
					if (board[nr][nc] == '#' || board[nr][nc] == '*')
						continue;
					board[nr][nc] = '*';
					pair<int, int> next;
					next.first = nr, next.second = nc;
					save_f.push_back(next);
				}
			}
			for (int i = 0; i < save_f.size(); i++)
				fire.push(save_f[i]);
			for (int i = 0; i < save_p.size(); i++)
			{
				if (board[save_p[i].first][save_p[i].second] == '*')
					continue;
				people.push(save_p[i]);
				visited[save_p[i].first][save_p[i].second] = 1;
			}
			if (people.empty())
				break;
			time++;
		}
		if (answer == 987654321)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << answer << '\n';
	}
}
