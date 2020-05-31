// 나무 재테크 3회 : 54분
// https://www.acmicpc.net/problem/16235
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dr[8] = { -1, -1,-1,0,0,1,1,1 };
const int dc[8] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K, answer;

int board[11][11], dead[11][11], add_energy[11][11];
vector <int> tree[11][11];

void solve()
{
	int year = 0;
	while (year < K)
	{
		// 봄, 여름
		for (int r = 1; r <= N; r++)
		{
			for (int c = 1; c <= N; c++)
			{
				if (!tree[r][c].empty())
				{
					vector <int> new_tree;

					sort(tree[r][c].begin(), tree[r][c].end());
					for (int i = 0; i < tree[r][c].size(); i++)
					{
						int age = tree[r][c][i];
						if (board[r][c] >= age)
						{
							board[r][c] -= age;
							tree[r][c][i] += 1;
							new_tree.push_back(age + 1);
						}
						else
							dead[r][c] += (age / 2);
					}
					tree[r][c].clear();
					tree[r][c] = new_tree;
					board[r][c] += dead[r][c];
					dead[r][c] = 0;
				}
			}
		}
		// 가을, 겨울
		for (int r = 1; r <= N; r++)
		{
			for (int c = 1; c <= N; c++)
			{
				board[r][c] += add_energy[r][c];
				if (!tree[r][c].empty())
				{
					for (int i = 0; i < tree[r][c].size(); i++)
					{
						if (tree[r][c][i] % 5 != 0)
							continue;
						for (int dir = 0; dir < 8; dir++)
						{
							int nr = r + dr[dir], nc = c + dc[dir];
							if (nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1)
								continue;
							tree[nr][nc].push_back(1);
						}

					}
				}

			}
		}
		year++;
	}
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			answer += tree[r][c].size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	answer = 0;
	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			cin >> add_energy[r][c];
			board[r][c] = 5;
		}
	for (int i = 0; i < M; i++)
	{
		int r, c, z;
		cin >> r >> c >> z;
		tree[r][c].push_back(z);
	}
	solve();
	cout << answer << '\n';
}