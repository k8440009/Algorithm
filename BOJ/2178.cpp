// 미로 탐색
// https://www.acmicpc.net/problem/2178
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main()
{
    int n, m;
    cin >> n >> m;

    int board[MAX][MAX];
    bool visied[MAX][MAX];
    int dist[MAX][MAX];
    fill_n(board[0], MAX * MAX, 0);
    fill_n(visied[0], MAX * MAX, 0);
    fill_n(dist[0], MAX * MAX, 0);

    for (int i = 0; i < n; i++)
    {
        string str = "";
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    // (0,0) ~ (N-1, M-1)
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    visied[0][0] = true;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == 0 || visied[nx][ny] > 0)
                continue;

            q.push({nx, ny});
            visied[nx][ny] = true;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    cout << dist[n - 1][m - 1] << '\n';

    return 0;
}