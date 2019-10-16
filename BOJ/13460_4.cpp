// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
const int MAX = 10 + 1;
struct INFO
{
    int ry, rx, by, bx, count;
};
INFO start;
int N, M;
char board[MAX][MAX];
int bfs()
{
    int result = -1;
    int visited[MAX][MAX][MAX][MAX]{
        0,
    };
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;
    while (!q.empty())
    {
        INFO cur = q.front();
        q.pop();
        if (cur.count > 10)
            break;
        if (board[cur.ry][cur.rx] == 'O' && board[cur.by][cur.bx] != 'O')
        {
            result = cur.count;
            break;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nextRy = cur.ry;
            int nextRx = cur.rx;
            int nextBy = cur.by;
            int nextBx = cur.bx;
            // 빨강
            while (1)
            { // 벽이거나 구멍이 아니면
                if (board[nextRy][nextRx] != '#' && board[nextRy][nextRx] != 'O')
                    nextRy += dy[dir], nextRx += dx[dir]; // 움직여야함
                // 벽 또는 구멍 일 때
                else
                {
                    if (board[nextRy][nextRx] == '#')
                        nextRy -= dy[dir], nextRx -= dx[dir];
                    break;
                }
            }
            // 파랑
            while (1)
            { // 벽이거나 구멍이 아니면
                if (board[nextBy][nextBx] != '#' && board[nextBy][nextBx] != 'O')
                    nextBy += dy[dir], nextBx += dx[dir]; // 움직여야함
                // 벽 또는 구멍 일 때
                else
                {
                    if (board[nextBy][nextBx] == '#')
                        nextBy -= dy[dir], nextBx -= dx[dir];
                    break;
                }
            }
            // 겹치는 경우
            if (nextRy == nextBy && nextRx == nextBx)
            {
                if (board[nextRy][nextRx] != 'O')
                {
                    int redDist = abs(nextRy - cur.ry) + abs(nextRx - cur.rx);
                    int blueDist = abs(nextBy - cur.by) + abs(nextBx - cur.bx);
                    // 한칸씩 뒤로
                    if (redDist > blueDist)
                        nextRy -= dy[dir], nextRx -= dx[dir];
                    else
                        nextBy -= dy[dir], nextBx -= dx[dir];
                }
            }
            // 이전에 방문하지 않은 경우
            if (visited[nextRy][nextRx][nextBy][nextBx] == 0)
            {
                visited[nextRy][nextRx][nextBy][nextBx] == 1;
                INFO next;
                next.ry = nextRy;
                next.rx = nextRx;
                next.by = nextBy;
                next.bx = nextBx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> board[i];
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (board[y][x] == 'R')
                start.ry = y, start.rx = x;
            else if (board[y][x] == 'B')
                start.by = y, start.bx = x;
        }
    }
    start.count = 0;
    int answer = bfs();
    cout << answer << '\n';
    return 0;
}