// 토마토
// https://www.acmicpc.net/problem/7569
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int dz[] = {0, 0, 0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0, 0, 0};
const int dx[] = {0, 0, 1, -1, 0, 0};
const int MAX = 100 + 1;
struct POS
{
    int y, x, z;
};
int board[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int N, M, H;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    fill_n(dist[0][0], MAX * MAX * MAX, -1);
    queue<POS> q;

    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                cin >> board[z][y][x];

                if (board[z][y][x] == 1)
                {
                    POS pos;
                    pos.z = z, pos.y = y, pos.x = x;
                    q.push(pos);
                    dist[z][y][x] = 0;
                }
            }
        }
    }

    int time = 0;

    while (!q.empty())
    {
        POS cur = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            POS next;
            next.z = cur.z + dz[dir];
            next.y = cur.y + dy[dir];
            next.x = cur.x + dx[dir];

            if (next.z < 0 || next.z >= H || next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.z][next.y][next.x] == -1)
                continue;

            if (dist[next.z][next.y][next.x] == -1 && board[next.z][next.y][next.x] == 0)
            {
                dist[next.z][next.y][next.x] = dist[cur.z][cur.y][cur.x] + 1;
                board[next.z][next.y][next.x] = 1;
                q.push(next);
                time = dist[next.z][next.y][next.x];
            }
        }
    }

    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (board[z][y][x] == 0)
                {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << time << '\n';
    return 0;
}