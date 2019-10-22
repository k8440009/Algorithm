// 나이트 이동
// https://www.acmicpc.net/problem/7562
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 300 + 1;
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int N;
int sy, sx, targetY, targetX;
int dist[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> N;
        cin >> sy >> sx;
        cin >> targetY >> targetX;

        fill_n(dist[0], MAX * MAX, -1);

        queue<pair<int, int>> q;
        q.push(make_pair(sy, sx));
        dist[sy][sx] = 0;

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            if (cur.first == targetY && cur.second == targetX)
                break;

            for (int dir = 0; dir < 8; dir++)
            {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue;

                if (dist[ny][nx] == -1)
                {
                    q.push(make_pair(ny, nx));
                    dist[ny][nx] = dist[cur.first][cur.second] + 1;
                }
            }
        }

        cout << dist[targetY][targetX] << '\n';
    }
}