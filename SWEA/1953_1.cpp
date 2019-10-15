// 1953. [모의 SW 역량테스트] 탈주범 검거
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct NODE
{
    int y, x, direction, time;
};
const int MAX = 50 + 1;
int N, M, R, C, L;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool check(int dir, int y, int x)
{
    if (dir == 0)
    {
        if (board[y][x] == 3 || board[y][x] == 4 || board[y][x] == 7)
            return true;
    }
    else if (dir == 1)
    {
        if (board[y][x] == 2 || board[y][x] == 4 || board[y][x] == 5)
            return true;
    }
    else if (dir == 2)
    {
        if (board[y][x] == 3 || board[y][x] == 5 || board[y][x] == 6)
            return true;
    }
    else if (dir == 3)
    {
        if (board[y][x] == 2 || board[y][x] == 6 || board[y][x] == 7)
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        // 세로 가로, 맨홀 y위치, x위치, 지난 시간
        cin >> N >> M >> R >> C >> L;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
                cin >> board[y][x];
        }

        fill_n(visited[0], MAX * MAX, 0);
        NODE start;
        start.y = R;
        start.x = C;
        start.time = 0;
        start.direction = board[start.y][start.x];
        queue<NODE> q;
        q.push(start);
        visited[start.y][start.x] = true;

        while (!q.empty())
        {
            NODE cur = q.front();
            q.pop();

            cur.time += 1;
            if (cur.time == L)
                break;
            // 4방향
            if (cur.direction == 1)
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    NODE next;
                    next.y = cur.y + dy[dir];
                    next.x = cur.x + dx[dir];

                    if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 0 || visited[next.y][next.x])
                        continue;
                    if (check(dir, next.y, next.x))
                        continue;

                    next.direction = board[next.y][next.x];
                    next.time = cur.time;

                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
            // 상, 하
            else if (cur.direction == 2)
            {
                for (int dir = 0; dir < 4; dir += 2)
                {
                    NODE next;
                    next.y = cur.y + dy[dir];
                    next.x = cur.x + dx[dir];

                    if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 0 || visited[next.y][next.x])
                        continue;
                    if (check(dir, next.y, next.x))
                        continue;

                    next.direction = board[next.y][next.x];
                    next.time = cur.time;
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
            // 좌,우
            else if (cur.direction == 3)
            {
                for (int dir = 1; dir < 4; dir += 2)
                {
                    NODE next;
                    next.y = cur.y + dy[dir];
                    next.x = cur.x + dx[dir];

                    if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 0 || visited[next.y][next.x])
                        continue;
                    if (check(dir, next.y, next.x))
                        continue;

                    next.direction = board[next.y][next.x];
                    next.time = cur.time;
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
            // 상,우
            else if (cur.direction == 4)
            {
                for (int dir = 0; dir <= 1; dir++)
                {
                    NODE next;
                    next.y = cur.y + dy[dir];
                    next.x = cur.x + dx[dir];

                    if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 0 || visited[next.y][next.x])
                        continue;
                    if (check(dir, next.y, next.x))
                        continue;

                    next.direction = board[next.y][next.x];
                    next.time = cur.time;
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
            // 하 우
            else if (cur.direction == 5)
            {
                for (int dir = 1; dir <= 2; dir++)
                {
                    NODE next;
                    next.y = cur.y + dy[dir];
                    next.x = cur.x + dx[dir];
                    next.direction = board[next.y][next.x];

                    if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 0 || visited[next.y][next.x])
                        continue;
                    if (check(dir, next.y, next.x))
                        continue;

                    next.direction = board[next.y][next.x];
                    next.time = cur.time;
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
            // 하 좌
            else if (cur.direction == 6)
            {
                for (int dir = 2; dir <= 3; dir++)
                {
                    NODE next;
                    next.y = cur.y + dy[dir];
                    next.x = cur.x + dx[dir];

                    if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 0 || visited[next.y][next.x])
                        continue;
                    if (check(dir, next.y, next.x))
                        continue;

                    next.direction = board[next.y][next.x];
                    next.time = cur.time;
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
            // 상 좌
            else if (cur.direction == 7)
            {
                for (int dir = 0; dir < 4; dir += 3)
                {
                    NODE next;
                    next.y = cur.y + dy[dir];
                    next.x = cur.x + dx[dir];

                    if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 0 || visited[next.y][next.x])
                        continue;
                    if (check(dir, next.y, next.x))
                        continue;

                    next.direction = board[next.y][next.x];
                    next.time = cur.time;
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
        }

        int answer = 0;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (visited[y][x])
                    answer += 1;
            }
        }

        cout << "#" << ts << ' ' << answer << '\n';
    }
    return 0;
}