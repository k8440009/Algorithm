// 나무 재테크
// https://www.acmicpc.net/problem/16235
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10 + 1;
const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M, K;
int board[MAX][MAX];
int add[MAX][MAX];
vector<int> tree[MAX][MAX];
void winter()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (add[r][c] > 0)
				board[r][c] += add[r][c];
		}
	}
}

void fall()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (!tree[r][c].empty())
			{
				int size = tree[r][c].size();
				for (int i = 0; i < size; i++)
				{
					if (tree[r][c][i] % 5 == 0)
					{
						for (int dir = 0; dir < 8; dir++)
						{
							int nr = r + dr[dir];
							int nc = c + dc[dir];
							if (nr < 0 || nr >= N || nc < 0 || nc >= N)
								continue;
							tree[nr][nc].push_back(1);
						}
					}
				}
			}
		}
	}
}
void spring_summer()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (!tree[r][c].empty())
			{
				int size = tree[r][c].size();
				int energy = 0;
				vector<int> new_tree;

				sort(tree[r][c].begin(), tree[r][c].end());
				for (int i = 0; i < size; i++)
				{
					if (board[r][c] < tree[r][c][i])
						energy += (tree[r][c][i] / 2);
					else
					{
						board[r][c] -= tree[r][c][i];
						tree[r][c][i]++;
						new_tree.push_back(tree[r][c][i]);
					}
				}
				tree[r][c].clear();
				tree[r][c].resize(new_tree.size());
				for (int i = 0; i < new_tree.size(); i++)
					tree[r][c][i] = new_tree[i];
				board[r][c] += energy;
			}
		}
	}
}
void print()
{
	int answer = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (!tree[r][c].empty())
				answer += (tree[r][c].size());
		}
	}
	cout << answer << '\n';
}

void solve()
{
	for (int i = 0; i < K; i++)
	{
		spring_summer();
		fall();
		winter();
	}
}
void init()
{
	cin >> N >> M >> K; // 땅 크기, 나무 갯수, 년도
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
		{
			cin >> add[r][c];
			board[r][c] = 5;
		}
	for (int i = 0; i < M; i++)
	{
		int x, y, age;
		cin >> y >> x >> age;
		y -= 1, x -= 1;
		tree[y][x].push_back(age);
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