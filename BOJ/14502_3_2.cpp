// 연구소 - 44ms
// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 9;
const int dr[] = {1,0,-1,0};
const int dc[] = {0,1,0,-1};

int 	N,M, safe_zone;
int		board[MAX][MAX];
bool	visited[MAX][MAX];

vector <pair<int,int>> virus_pos;

void	spread_virus()
{
	queue <pair<int,int>> q;

	fill_n(visited[0], MAX * MAX, false);

	for(int i = 0; i < virus_pos.size(); i++)
	{
		int s_r = virus_pos[i].first, s_c = virus_pos[i].second;
		q.push(make_pair(s_r, s_c));
		visited[s_r][s_c] = true;
	}

	while (!q.empty())
	{
		pair<int,int> cur = q.front();
		q.pop();
		for(int dir = 0; dir < 4; dir++)
		{
			int nr = cur.first + dr[dir];
			int nc = cur.second + dc[dir];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || board[nr][nc] == 1)
				continue;
			q.push(make_pair(nr, nc));
			visited[nr][nc] = true;
		}
	}

	int		tmp_zone = 0;
	for (int r = 0; r < N; r++)
	{
		for(int c = 0; c < M; c++)
		{
			if (board[r][c] == 0 && !visited[r][c])
				tmp_zone++;
		}
	}
	if (tmp_zone > safe_zone)
		safe_zone = tmp_zone;
}

void	dfs(int s_r, int s_c, int wall_cnt)
{
	if (wall_cnt == 3)
	{
		spread_virus();
		return ;
	}
	
	for (int r = s_r; r < N; r++)
	{
		for(int c = s_c; c < M; c++)
		{
			if (board[r][c] == 1 || board[r][c] == 2)
				continue;
			board[r][c] = 1;
			dfs(r, c, wall_cnt + 1);
			board[r][c] = 0;
		}
		s_c = 0;
	}
}
int 	main()
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
			if (board[r][c] == 2)
				virus_pos.push_back(make_pair(r,c));
		}
	}
	dfs(0, 0, 0);
	cout << safe_zone << '\n';
}