// 불 메모리 초과
// https://www.acmicpc.net/problem/5427
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct STATE
{
	int time, r, c;
};

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int W, H;

int board[1002][1002];
bool visited[1002][1002];
vector<STATE> save_p, save_f;

void print_board(int src[1002][1002])
{
	cout << '\n';
	for (int r = 1; r <= H; r++)
	{
		for (int c = 1; c <= W; c++)
		{
			cout << src[r][c] << ' ';
		}
		cout << '\n';
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
		int answer = 987654321;
		cin >> W >> H;
		fill_n(board[0], 1002 * 1002, -1);
		fill_n(visited[0], 1002 * 1002, 0);

		queue<STATE> fire, people;

		for (int r = 1; r <= H; r++)
		{
			string tmp;
			cin >> tmp;
			for (int c = 1; c <= W; c++)
			{
				if (tmp[c - 1] == '.')
					board[r][c] = 0;
				else if (tmp[c - 1] == '#')
					board[r][c] = 1;
				else if (tmp[c - 1] == '*')
				{
					STATE st;
					board[r][c] = 2;
					st.r = r, st.c = c, st.time = 0;
					fire.push(st);
				}
				else
				{
					STATE st;
					st.r = r, st.c = c, st.time = 0;
					people.push(st);
					board[r][c] = 0;
					visited[r][c] = 1;
				}
			}
		}

		bool flag = 1;
		int time = 0;
		while (!people.empty())
		{
			// 1. 상근이가 움직인다.
			while (!people.empty())
			{
				STATE cur = people.front();
				people.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nr = cur.r + dr[dir], nc = cur.c + dc[dir];
					if (nr <= 0 || nr >= H + 1 || nc <= 0 || nc >= W + 1)
					{
						if (answer > cur.time + 1)
							answer = cur.time + 1;
						flag = 0;
						break;
					}
					if (board[nr][nc] == 1 || board[nr][nc] == 2 || visited[nr][nc] == 1)
						continue;
					STATE next;
					next.r = nr, next.c = nc, next.time = cur.time + 1;
					save_p.push_back(next);
				}
			}
			if (!flag)
				break;
			// 2. 불이 움직인다.
			while (!fire.empty())
			{
				STATE cur = fire.front();
				fire.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nr = cur.r + dr[dir], nc = cur.c + dc[dir];
					if (nr <= 0 || nr >= H + 1 || nc <= 0 || nc >= W + 1)
						continue;
					if (board[nr][nc] == 1 || board[nr][nc] == 2)
						continue;
					board[nr][nc] = 2;
					STATE next;
					next.r = nr, next.c = nc, next.time = cur.time + 1;
					save_f.push_back(next);
				}
			}
			for (int i = 0; i < save_f.size(); i++)
				fire.push(save_f[i]);
			for (int i = 0; i < save_p.size(); i++)
			{
				if (board[save_p[i].r][save_p[i].c] == 2)
					continue;
				people.push(save_p[i]);
				visited[save_p[i].r][save_p[i].c] = 1;
			}
			save_p.clear(), save_f.clear();
			if (people.empty() && fire.empty())
				flag = 0;
		}
		if (answer == 987654321)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << answer << '\n';
	}
}