// 인구이동 3회차
// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 50 + 2;
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

struct POS
{
	int r, c;
};

int N,L,R, day;
int board[MAX][MAX];

void print_board()
{
	cout << '\n';
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << board[r][c] << ' ';
 		}
		 cout << '\n';
	}
}

bool move_people()
{
	bool visited[MAX][MAX];
	bool flag = false;
	fill_n(visited[0], MAX * MAX, 0);

	for (int r = 0; r < N; r++)
	{
		for(int c = 0; c < N; c++)
		{
			if (visited[r][c])
				continue;

			int total = 0;
			POS start;
			queue <POS> q;
			vector <POS> country;

			start.r = r, start.c = c;
			q.push(start);
			visited[start.r][start.c] = 1;
			while (!q.empty())
			{
				POS cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nr = cur.r + dr[dir], nc = cur.c + dc[dir];
				
					if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
						continue;
					
					if (abs(board[nr][nc] - board[cur.r][cur.c]) >= L && abs(board[nr][nc] - board[cur.r][cur.c]) <= R)
					{
						POS next;
						next.r = nr, next.c = nc;

						q.push(next);
						country.push_back(next);
						visited[nr][nc] = 1;
						total += board[nr][nc];
					}
				}
			}
			if (country.size() > 0)
			{
				flag = true;
				country.push_back(start);
				total += board[start.r][start.c];
				int qout = total / country.size();
				for (int i = 0; i < country.size(); i++)
					board[country[i].r][country[i].c] = qout;
				// print_board();
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
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];

	while (true)
	{
		if (!move_people())
			break;
		else
			day += 1;
	}
	cout << day << '\n';
}