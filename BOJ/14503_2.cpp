// 로봇 청소기 2회차 : 180분
// https://www.acmicpc.net/problem/14503
#include <iostream>
using namespace std;

const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };

struct ROBOT
{
	int r, c, dir;
};

ROBOT robot;
int N, M;
int board[52][52];
bool visited[52][52];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	cin >> robot.r >> robot.c >> robot.dir;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> board[r][c];
	int answer = 0;
	while (true)
	{
		if (board[robot.r][robot.c] == 0 && !visited[robot.r][robot.c])
		{
			visited[robot.r][robot.c] = 1;
			answer++;
		}
		int next_dir, nr, nc, cnt;
		bool flag = 1;
		for (cnt = 0; cnt < 4; cnt++)
		{
			next_dir = ((robot.dir - 1) + 4) % 4;
			nr = robot.r + dr[next_dir], nc = robot.c + dc[next_dir];
			if (board[nr][nc] == 0 && !visited[nr][nc])
			{
				robot.r = nr, robot.c = nc, robot.dir = next_dir;
				break;
			}
			else if (board[nr][nc] == 1 || (board[nr][nc] == 0 && visited[nr][nc]))
			{
				robot.dir = next_dir;
				continue;
			}
		}
		if (cnt == 4 || board[nr][nc] == 1)
		{
			int back_dir = (robot.dir + 2) % 4;
			int nr = robot.r + dr[back_dir], nc = robot.c + dc[back_dir];
			if (board[nr][nc] == 1)
				break;
			robot.r = nr, robot.c = nc;
		}
	}
	cout << answer << '\n';
}