#include <bits/stdc++.h>
using namespace std;

struct ROBOT
{
    int y, x, dir;
};
ROBOT robot;
const int MAX = 50;
int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
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
        {
            cin >> board[i][j];
        }
    }

    queue<ROBOT> q;
    q.push(robot);
    int answer = 0;

    while (!q.empty())
    {
        ROBOT cur = q.front();
        q.pop();

        // 1.
        if (board[cur.y][cur.x] == 0)
        {
            board[cur.y][cur.x] = 2;
            answer += 1;
        }
        // 2.
        for (int dir = 0; dir < 4; dir++)
        {
            ROBOT next;

            next.dir = (cur.dir + 3) % 4;
            next.y = cur.y + dy[next.dir];
            next.x = cur.x + dx[next.dir];

            if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] != 0)
            {
                cur.dir = next.dir;
                continue;
            }

            q.push(next);
            break;
        }

        if (q.empty())
        {
            ROBOT next;
            next.dir = (cur.dir + 2) % 4;
            next.y = cur.y + dy[next.dir];
            next.x = cur.x + dx[next.dir];
            next.dir = cur.dir;

            if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 1)
                break;

            q.push(next);
        }
    }

    cout << answer << '\n';
    return 0;
}