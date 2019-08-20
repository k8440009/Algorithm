// 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX][2]; // 0 : 벽 안깸, 1 : 벽 깨기 사용

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    visited[0][0] = true;
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        /* code */
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // 벽 안 부수는 경우
            if (board[nx][ny] == 0 && dist[nx][ny][z] == 0)
            {
                q.push(make_tuple(nx, ny, z));
                dist[nx][ny][z] = dist[x][y][z] + 1;
            }
            // 벽 부수는 경우
            if (z == 0 && board[nx][ny] == 1 && dist[nx][ny][z + 1] == 0)
            {
                q.push(make_tuple(nx, ny, z + 1));
                dist[nx][ny][z + 1] = dist[x][y][z] + 1;
            }
        }
    }

    if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0)
        cout << min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    else if (dist[n - 1][m - 1][0] != 0)
        cout << dist[n - 1][m - 1][0];
    else if (dist[n - 1][m - 1][1] != 0)
        cout << dist[n - 1][m - 1][1];
    else
        cout << -1;
    cout << '\n';

    return 0;
}