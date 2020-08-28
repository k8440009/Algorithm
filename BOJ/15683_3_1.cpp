// 감시
// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 8 + 1;
const int INF = 987654321;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

struct CCTV
{
	int r, c, type, dir;
};

int N,M, answer = INF;
int	board[MAX][MAX];
int visited[MAX][MAX];
vector <CCTV> cctv;

void sight(CCTV cur, int dir)
{
	int r = cur.r, c = cur.c;
	visited[r][c] = 1;
	while (true)
	{
		int nr = r + dr[dir], nc = c + dc[dir];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == 6)
			break;
		visited[nr][nc] = 1;
		r = nr, c = nc;
	}
}

void check_cctv_sight()
{
	fill_n(visited[0], MAX * MAX, 0);
	for (int i = 0; i < cctv.size(); i++)
	{
		if (cctv[i].type == 1)
		{
			if (cctv[i].dir == 0)
				sight(cctv[i], 0);
			else if (cctv[i].dir == 1)
				sight(cctv[i], 1);
			else if (cctv[i].dir == 2)
				sight(cctv[i], 2);
			else if (cctv[i].dir == 3)
				sight(cctv[i], 3);
		}
		else if (cctv[i].type == 2)
		{
			if ((cctv[i].dir % 2) == 0)
			{
				sight(cctv[i], 1);
				sight(cctv[i], 3);
			}
			else if ((cctv[i].dir % 2) == 1)
			{
				sight(cctv[i], 0);
				sight(cctv[i], 2);
			}
		}
		else if (cctv[i].type == 3)
		{
			if (cctv[i].dir == 0)
			{
				sight(cctv[i], 0);
				sight(cctv[i], 1);
			}
			else if (cctv[i].dir == 1)
			{
				sight(cctv[i], 1);
				sight(cctv[i], 2);
			}
			else if (cctv[i].dir == 2)
			{
				sight(cctv[i], 2);
				sight(cctv[i], 3);
			}
			else if (cctv[i].dir == 3)
			{
				sight(cctv[i], 3);
				sight(cctv[i], 0);
			}
		}
		else if (cctv[i].type == 4)
		{
			if (cctv[i].dir == 0)
			{
				sight(cctv[i], 3);
				sight(cctv[i], 0);
				sight(cctv[i], 1);
			}
			else if (cctv[i].dir == 1)
			{
				sight(cctv[i], 0);
				sight(cctv[i], 1);
				sight(cctv[i], 2);
			}
			else if (cctv[i].dir == 2)
			{
				sight(cctv[i], 1);
				sight(cctv[i], 2);
				sight(cctv[i], 3);
			}
			else if (cctv[i].dir == 3)
			{
				sight(cctv[i], 2);
				sight(cctv[i], 3);
				sight(cctv[i], 0);
			}
		}
		else if (cctv[i].type == 5)
		{
			sight(cctv[i], 0);
			sight(cctv[i], 1);
			sight(cctv[i], 2);
			sight(cctv[i], 3);
		}
	}
	int total = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			if (!visited[r][c] && board[r][c] != 6)
				total += 1;
	answer = min(answer, total);
}
void dfs(int cnt)
{
	if (cnt == cctv.size())
	{
		check_cctv_sight();
		return ;
	}
	for (int dir = 0; dir < 4; dir++)
	{
		cctv[cnt].dir = dir;
		dfs(cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for(int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] >= 1 && board[r][c] <= 5)
			{
				CCTV tmp;
				tmp.r = r, tmp.c = c, tmp.type = board[r][c];
				cctv.push_back(tmp);
			}
		}
	}
	dfs(0);
	cout << answer << '\n';
}