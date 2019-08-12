// 알고 스팟
// https://www.acmicpc.net/problem/1261
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int MAX = 100;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // bfs
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string str = "";
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> nextQueue;
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny])
                continue;

            if (board[nx][ny] == 0)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cur.first][cur.second];
            }
            else
            {
                nextQueue.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }

        if (q.empty())
        {
            q = nextQueue;
            nextQueue = queue<pair<int, int>>();
        }
    }

    cout << dist[m - 1][n - 1];

    return 0;
}