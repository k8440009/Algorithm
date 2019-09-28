// 로봇 청소기
// https://www.acmicpc.net/problem/14503
#include <bits/stdc++.h>
using namespace std;
struct ROBOT
{
    int y, x, dir;
};

ROBOT robot;

const int MAX = 50;
int N, M;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int board[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    cin >> robot.y >> robot.x >> robot.dir;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    queue<ROBOT> q;
    q.push(robot);

    int answer = 0;
    while (!q.empty())
    {
        ROBOT now = q.front();
        q.pop();

        // 1. 현재 위치 청소
        if (board[now.y][now.x] == 0)
        {
            board[now.y][now.x] = 2;
            answer += 1;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            /*
                왼쪽방향으로 회전하는 공식을 만듬
                cur.dir = 0;    // 북쪽
                dir = 0;
                (now.dir + 3 - dir) % 4 = (now.dir + 3 + dir*3) %4

                (now.dir + 3 - dir) % 4 = 3 (서쪽)
                (now.dir + 3 - dir) % 4 = 3 (서쪽)
                (now.dir + 3 - dir) % 4 = 3 (서쪽)
                (now.dir + 3 - dir) % 4 = 3 (서쪽)
            */
            // 왼쪽 방향 부터
            ROBOT next;
            next.dir = (now.dir + 3 - dir) % 4;
            next.y = now.y + dy[next.dir];
            next.x = now.x + dx[next.dir];

            // 청소할 공간이 없으면 pass
            if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] != 0)
                continue;

            q.push(next);
            break; // 청소기 하나이므로
        }

        // 네 방향이 청소되어있거나, 벽인 경우
        if (q.empty())
        {
            ROBOT next;
            next.dir = now.dir;
            // 후진
            next.y = now.y + dy[(next.dir + 2) % 4];
            next.x = now.x + dx[(next.dir + 2) % 4];

            // 청소할 공간이 없으면 멈춘다.
            if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 1)
                break;

            q.push(next);
        }
    }

    cout << answer << '\n';
    return 0;
}