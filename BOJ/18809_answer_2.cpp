// Gaaaaaaaaaarden, 조합(next_permutaion) + bfs()
// https://www.acmicpc.net/problem/18809
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int answer;
int N, M, G, R;
int board[52][52];
// 백트래킹을 위한 변수
int selected[10];
// 초록, 빨랑 개뱡액으로 선택한 위치의 index
int chosen_g[5], chosen_r[5];

vector<pair<int, int>> candi;
int candi_size;

int bfs()
{
	int cnt = 0;
	pair<int, int> state[52][52]; // {arrivial time, color}

	queue<pair<int, int>> q;
	for (int i = 0; i < G; i++)
	{
		state[candi[chosen_g[i]].first][candi[chosen_g[i]].second] = make_pair(0, GREEN);
		q.push(candi[chosen_g[i]]);
	}
	for (int i = 0; i < R; i++)
	{
		state[candi[chosen_r[i]].first][candi[chosen_r[i]].second] = make_pair(0, RED);
		q.push(candi[chosen_r[i]]);
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		int cur_time = state[cur.first][cur.second].first;
		int cur_color = state[cur.first][cur.second].second;

		if (state[cur.first][cur.second].second == FLOWER)
			continue;
		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.first + dr[dir];
			int nc = cur.second + dc[dir];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == 0)
				continue;
			if (state[nr][nc].second == EMPTY)
			{
				state[nr][nc] = make_pair(cur_time + 1, cur_color);
				q.push(make_pair(nr, nc));
			}
			else if (state[nr][nc].second == RED)
			{
				if (cur_color == GREEN && state[nr][nc].first == cur_time + 1)
				{
					cnt++;
					state[nr][nc].second = FLOWER;
				}
			}
			else if (state[nr][nc].second == GREEN)
			{
				if (cur_color == RED && state[nr][nc].first == cur_time + 1)
				{
					cnt++;
					state[nr][nc].second = FLOWER;
				}
			}
		}
	}
	return cnt;
}

void dfs_r(int idx)
{
	if (idx == R)
	{
		answer = max(answer, bfs());
		return;
	}

	int cur = 0;
	if (idx != 0)
		cur = chosen_r[idx - 1] + 1;
	while (cur < candi_size)
	{
		if (selected[cur])
		{
			cur++;
			continue;
		}

		selected[cur] = 1;
		chosen_r[idx] = cur;
		dfs_r(idx + 1);
		selected[cur] = 0;
		cur++;
	}
}

void dfs_g(int idx)
{
	if (idx == G)
	{
		dfs_r(0);
		return;
	}

	int cur = 0;
	if (idx != 0)
		cur = chosen_g[idx - 1] + 1;
	while (cur < candi_size)
	{
		selected[cur] = 1;
		chosen_g[idx] = cur;
		dfs_g(idx + 1);
		selected[cur] = 0;
		cur++;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> G >> R;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] == 2)
				candi.push_back(make_pair(r, c));
		}
	}

	candi_size = candi.size();
	dfs_g(0);
	cout << answer << '\n';
}