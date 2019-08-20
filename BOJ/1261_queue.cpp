// 알고스팟
// https://www.acmicpc.net/problem/1261
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int board[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        string str = "";
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> next;
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny])
                continue;

            // 벽 있으면 뒤에 삽입, 없으면 앞에 삽입
            if (board[nx][ny] == 0)
            {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y];
            }

            else
            {
                next.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }

            visited[nx][ny] = 1;
        }

        if (q.empty())
        {
            q = next;
            next = queue<pair<int, int>>();
        }
    }

    cout << dist[M - 1][N - 1] << '\n';
    return 0;
}