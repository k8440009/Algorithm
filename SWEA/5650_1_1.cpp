// 5650. [모의 SW 역량테스트] 핀볼 게임
#include <iostream>
#include <vector>
using namespace std;

struct BALL
{
	int r, c, dir;
};

BALL ball;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer, N;
int board[102][102];
vector<pair<int, int>> hole;

void change_dir(int block)
{

	if (block == 1)
	{
		if (ball.dir == 2)
			ball.dir = 1;
		else if (ball.dir == 3)
			ball.dir = 0;
		else
			ball.dir = (ball.dir + 2) % 4;
	}
	else if (block == 2)
	{
		if (ball.dir == 0)
			ball.dir = 1;
		else if (ball.dir == 3)
			ball.dir = 2;
		else
			ball.dir = (ball.dir + 2) % 4;
	}
	else if (block == 3)
	{
		if (ball.dir == 0)
			ball.dir = 3;
		else if (ball.dir == 1)
			ball.dir = 2;
		else
			ball.dir = (ball.dir + 2) % 4;
	}
	else if (block == 4)
	{
		if (ball.dir == 2)
			ball.dir = 3;
		else if (ball.dir == 1)
			ball.dir = 0;
		else
			ball.dir = (ball.dir + 2) % 4;
	}
	else if (block == 5)
		ball.dir = (ball.dir + 2) % 4;
}

void solve(int s_r, int s_c, int b_dir)
{
	int point = 0;
	ball.r = s_r, ball.c = s_c, ball.dir = b_dir;
	while (true)
	{
		int nr = ball.r + dr[ball.dir], nc = ball.c + dc[ball.dir];
		// 종료 조건
		if (board[nr][nc] == -1 || (nr == s_r && nc == s_c))
			break;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
		{
			point++;
			ball.dir = (ball.dir + 2) % 4;
		}
		else if (board[nr][nc] >= 1 && board[nr][nc] <= 5) // 일반블록
		{
			point++;
			change_dir(board[nr][nc]);
		}
		else if (board[nr][nc] >= 6 && board[nr][nc] <= 10)
		{
			int num = board[nr][nc];
			for (int i = 0; i < hole.size(); i++)
			{
				if (num == board[hole[i].first][hole[i].second] && (hole[i].first != nr || hole[i].second != nc))
				{
					nr = hole[i].first, nc = hole[i].second;
					break;
				}
			}
		}
		ball.r = nr, ball.c = nc;
	}
	answer = max(answer, point);
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
		answer = 0;
		hole.clear();
		cin >> N;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
			{
				cin >> board[r][c];
				if (board[r][c] >= 6)
					hole.push_back(make_pair(r, c));
			}
		// 100 * 100 * 4
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (board[r][c] == 0)
				{
					for (int dir = 0; dir < 4; dir++)
						solve(r, c, dir);
				}
			}
		}
		cout << '#' << ts << ' ' << answer << '\n';
	}
}