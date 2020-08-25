// 로봇청소기 (리팩토링)
// https://www.acmicpc.net/problem/14503
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 50 + 1;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

struct ROBOT
{
	int r, c, dir;
};

ROBOT	robot;
int		N, M;
int		board[MAX][MAX];

int		main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ret = 0;

	cin >> N >> M;
	cin >> robot.r >> robot.c >> robot.dir;

	for (int r = 0; r < N; r++)
		for(int c = 0; c < M; c++)
			cin >> board[r][c];

	queue <ROBOT> q;
	q.push(robot);

	while (!q.empty())
	{
		ROBOT cur = q.front();
		q.pop();

		if (board[cur.r][cur.c] == 0)
		{
			board[cur.r][cur.c] = 2;
			ret++;
		}
	
		for (int dir = 0; dir < 4; dir++)
		{
			ROBOT next;
			next.dir = (cur.dir - 1 + 4 - dir) % 4;	// 이전과 다른 부분
			next.r = cur.r + dr[next.dir], next.c = cur.c + dc[next.dir];
			if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= M || board[next.r][next.c] != 0)
				continue;
			q.push(next);
			break;
		}
		// 큐가 비어있는 경우 -> 후진
		if (q.empty())
		{
			ROBOT next;
			next.dir = cur.dir;
			next.r = cur.r + dr[(next.dir + 2) % 4], next.c = cur.c + dc[(next.dir + 2) % 4];
			if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= M || board[next.r][next.c] == 1)
				break;
			q.push(next);
		}
	}
	cout << ret << '\n';
}