// 로봇 청소기
// https://www.acmicpc.net/problem/14503
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50 + 1;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
struct ROBOT
{
    int r, c, dir;
};
ROBOT robot;
int N, M;
int board[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    cin >> robot.r >> robot.c >> robot.dir;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == 0)
                board[y][x] = -1;
        }
    }

    int answer = 0;
    queue<ROBOT> q;
    q.push(robot);

    while (!q.empty())
    {
        ROBOT cur = q.front();
        q.pop();

        if (board[cur.r][cur.c] == -1)
        {
            board[cur.r][cur.c] = 0;
            answer += 1;
        }

        for (int direction = 0; direction < 4; direction++)
        {
            int nDir = (cur.dir + 3) % 4;
            int nr = cur.r + dr[nDir];
            int nc = cur.c + dc[nDir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] != -1)
            {
                cur.dir = nDir;
                continue;
            }

            ROBOT next;
            next.r = nr;
            next.c = nc;
            next.dir = nDir;
            q.push(next);
            break;
        }

        // 네 방향 청소
        while (q.empty())
        {
            ROBOT next;
            int nr = cur.r - dr[cur.dir];
            int nc = cur.c - dc[cur.dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == 1)
                break;

            next.r = nr;
            next.c = nc;
            next.dir = cur.dir;
            q.push(next);
        }
    }

    cout << answer << '\n';
    return 0;
}
