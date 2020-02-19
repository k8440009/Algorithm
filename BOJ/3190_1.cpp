// 뱀
// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100 + 2;
const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};
struct Animal
{
	int row = 1;
	int col = 1;
	int dir = 0;
};

Animal snake_head;

int board[MAX][MAX];
int N, K, L;
int time = 1;
vector<pair<int, char>> change_position;

void print()
{
	cout << time << '\n';
}
void solve()
{
	int index = 0;
	queue<pair<int, int>> snake_body;
	snake_body.push(make_pair(1, 1));
	board[1][1] = 2;

	while (1)
	{
		int nr = snake_head.row + dr[snake_head.dir];
		int nc = snake_head.col + dc[snake_head.dir];

		// printf("time : %d, (r,c) : %d %d, (nr,nc) : %d %d\n", time, snake_head.row, snake_head.col, nr, nc);
		if (nr < 1 || nr > N || nc < 1 || nc > N || board[nr][nc] == 2)
			break;

		if (board[nr][nc] == 1)
		{
			snake_head.row = nr, snake_head.col = nc;
			snake_body.push(make_pair(nr, nc));
			board[nr][nc] = 2;
		}
		else
		{
			snake_head.row = nr, snake_head.col = nc;
			board[snake_body.front().first][snake_body.front().second] = 0;
			snake_body.pop();
			board[nr][nc] = 2;
			snake_body.push(make_pair(nr, nc));
		}

		if (change_position[index].first == time)
		{
			if (change_position[index].second == 'L')
			{
				snake_head.dir -= 1;
				if (snake_head.dir < 0)
					snake_head.dir = 3;
			}
			else
			{
				snake_head.dir += 1;
				snake_head.dir %= 4;
			}
			index++;
		}
		time++;
	}
}

void init()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		board[r][c] = 1;
	}
	cin >> L;
	change_position.resize(L);
	for (int i = 0; i < L; i++)
	{
		int t;
		char dir;
		cin >> t >> dir;
		change_position[i].first = t;
		change_position[i].second = dir;
	}
}

int main()
{
	init();
	solve();
	print();
}