// 로봇 청소기
// https://www.acmicpc.net/problem/14503
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50 + 1;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct ROBOT
{
	int r, c, dir;
};
ROBOT cleaner;

int N, M, answer;
int board[MAX][MAX];
int visited[MAX][MAX];

void print()
{
	cout << answer << '\n';
}

void print_board(int desc[51][51])
{
	cout << '\n';
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cout << desc[r][c] << ' ';
		}
		cout << '\n';
	}

}

void solve()
{
	int cnt = 0;
	int flag = 1;

	while (1)
	{
		if (flag && !visited[cleaner.r][cleaner.c])
		{
			visited[cleaner.r][cleaner.c] = 1;
			answer++;
			flag = 0;
		}


		print_board(visited);

		int n_dir = ((cleaner.dir - 1) + 4) % 4;
		int nr = cleaner.r + dr[n_dir];
		int nc = cleaner.c + dc[n_dir];

		if (board[nr][nc] == 0 && !visited[nr][nc])
		{
			cleaner.dir = n_dir;
			cleaner.r = cleaner.r + dr[cleaner.dir];
			cleaner.c = cleaner.c + dc[cleaner.dir];
			flag = 1;
			cnt = 0;
			continue;
		}
		else if (cnt < 4 && (board[nr][nc] == 1 || (board[nr][nc] == 0 && visited[nr][nc])))
		{
			cleaner.dir = n_dir;
			cnt++;
			continue;
		}
		else if (cnt == 4 || board[nr][nc] == 1)
		{
			int back_dir = (cleaner.dir + 2) % 4;
			int back_r = cleaner.r + dr[back_dir];
			int back_c = cleaner.c + dc[back_dir];
			if (board[back_r][back_c] == 1)
				break;
			cleaner.r = back_r;
			cleaner.c = back_c;
			cnt = 0;
			flag = 1;
		}
	}
}

void init()
{
	cin >> N >> M;
	cin >> cleaner.r >> cleaner.c >> cleaner.dir;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> board[r][c];
}

int main()
{
	init();
	solve();
	print();
}