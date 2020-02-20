// 연구소
// https://www.acmicpc.net/problem/14502
#include <bits/stdc++.h>
using namespace std;
/*
    0. 맵을 복사
    1. 복사한 맵에 재귀로 벽을 세움
    2. 바이러스로 bfs
    3. 끝나면 0 지역을 센다
*/
const int MAX = 8;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int answer = 0;

int board[MAX][MAX];
int tempBoard[MAX][MAX];

void copyBoard(int (*a)[MAX], int (*b)[MAX])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			a[i][j] = b[i][j];
}

// 바이러스 움직임
void moveVirus()
{
	int spreadBoard[MAX][MAX];
	copyBoard(spreadBoard, tempBoard);

	queue<pair<int, int>> q;
	// 바이러스 찾음
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (spreadBoard[i][j] == 2)
				q.push({i, j});
		}
	}

	while (!q.empty())
	{
		int x, y;
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (spreadBoard[nx][ny] == 0)
			{
				spreadBoard[nx][ny] = 2;
				q.push({nx, ny});
			}
		}
	}

	// 안전지역
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (spreadBoard[i][j] == 0)
				cnt++;
		}
	}
	answer = max(answer, cnt);
}
// 벽 세우기
void makeWall(int cnt)
{
	if (cnt == 3)
	{
		moveVirus();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tempBoard[i][j] == 0)
			{
				tempBoard[i][j] = 1;
				makeWall(cnt + 1);
				tempBoard[i][j] = 0;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
			{
				copyBoard(tempBoard, board);
				tempBoard[i][j] = 1;
				makeWall(1);
				tempBoard[i][j] = 0;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}
