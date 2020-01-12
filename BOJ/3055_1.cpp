// 탈출
// https://www.acmicpc.net/problem/3055
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const int MAX = 50 + 1;

int board[MAX][MAX];
queue<pair<int, int>> q;

// 고슴도치
bool visited[MAX][MAX];
int dist[MAX][MAX];

// 물
bool waterVisited[MAX][MAX];
int water[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    int startX, startY;
    int goalX, goalY;

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < N; j++)
        {
            // 비어 있는 곳
            if (str[j] == '.')
                board[i][j] = 0;
            // 돌
            else if (str[j] == 'X')
                board[i][j] = 1;
            // 물
            else if (str[j] == '*')
            {
                q.push({i, j});
                waterVisited[i][j] = true;
                water[i][j] = 0;
            }
            // 고슴도치
            else if (str[j] == 'S')
            {
                startX = i;
                startY = j;
                visited[i][j] = true;
                dist[i][j] = 0;
            }
            // 비버집
            else if (str[j] == 'D')
            {
                board[i][j] = 2;
                goalX = i;
                goalY = j;
            }
        }
    }

    // 1. 물 먼저 이동
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if (waterVisited[nx][ny])
                continue;
            if (board[nx][ny] > 0)
                continue;

            q.push({nx, ny});
            waterVisited[nx][ny] = true;
            water[nx][ny] = water[x][y] + 1;
        }
    }

    // 2. 그 다음 고슴도치 이동
    q.push({startX, startY});
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny])
                continue;
            // 돌
            if (board[nx][ny] == 1)
                continue;

            if (water[nx][ny] != 0 && dist[x][y] + 1 >= water[nx][ny])
                continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
        }
    }

    if (dist[goalX][goalY] == 0)
        cout << "KAKTUS" << '\n';
    else
        cout << dist[goalX][goalY] << '\n';

    return 0;
}