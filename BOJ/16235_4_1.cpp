// 나무 재테크 4회
// https://www.acmicpc.net/problem/16235
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10 + 2;
const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N,M,K;

vector <int> trees[MAX][MAX];
int	board[MAX][MAX], add_energy[MAX][MAX];

void solve()
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (!trees[r][c].empty())
			{
				int dead_tree = 0;
				vector <int> new_tree;
				
				sort(trees[r][c].begin(), trees[r][c].end());
				
				for (int i = 0; i < trees[r][c].size(); i++)
				{
					int age = trees[r][c][i];
					if (board[r][c] - age >= 0)
					{
						board[r][c] -= age;
						new_tree.push_back(age + 1);
					}
					else
						dead_tree += (age / 2);
				}

				trees[r][c].clear();
				trees[r][c] = new_tree;
				board[r][c] += dead_tree;
			}
		}
	}

	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			board[r][c] += add_energy[r][c];
	
			if (!trees[r][c].empty())
			{
				for (int i = 0; i < trees[r][c].size(); i++)
				{
					int age = trees[r][c][i];

					if (age % 5 == 0)
					{
						for (int dir = 0; dir < 8; dir++)
						{
							int nr = r + dr[dir], nc = c + dc[dir];
							if (nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1)
								continue;
							trees[nr][nc].push_back(1);
						}
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			cin >> add_energy[r][c];
			board[r][c] = 5;
		}

	for (int i = 0; i < M; i++)
	{
		int r, c, age;
		cin >> r >> c >> age;

		trees[r][c].push_back(age);
	}

	while (K--)
		solve();

	int answer = 0;

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			answer += trees[r][c].size();
	
	cout << answer << '\n';
}