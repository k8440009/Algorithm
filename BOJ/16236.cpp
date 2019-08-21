// 아기 상어
// https://www.acmicpc.net/problem/16236
#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
/*
    아기상어
*/
int N;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int fishCnt[7];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int sharkSize = 2; // 상어 사이즈
int eatCnt = 0;    // 처먹은 횟수

int lastX = 0;
int lastY = 0;

int main()
{
    cin >> N;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            fishCnt[board[i][j]]++;
            if (board[i][j] > 0)
            {
                if (board[i][j] == 9)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                    dist[i][j] = 0;
                }
                else
                {
                    fishCnt[board[i][j]]++;
                }
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        bool check;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny])
                continue;

            // 상어 처먹는거 구현
            // 아긔 상어보다 클때
            if (board[nx][ny] > sharkSize)
            {
                continue;
            }
            // 아긔 상어랑 같을 때
            else if (board[nx][ny] == sharkSize)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
            }
            // 아긔 상어보다 작을 때
            else
            { // 물고기 인 경우
                if (board[nx][ny] > 0)
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;

                    board[nx][ny] = 0;
                    eatCnt += 1;
                    fishCnt[board[nx][ny]]--;
                    if (eatCnt == sharkSize)
                    {
                        sharkSize += 1;
                    }
                }
            }

            // 다 처먹었다면 종료
            check = true;
            for (int i = 1; i <= 6; i++)
            {
                if (fishCnt[i] != 0)
                {
                    check = false;
                    break;
                }
            }
            // 다 처먹은 경우
            if (check && eatCnt > 0)
            {
                cout << dist[nx][ny] << '\n';
                break;
            }
        }
    }

    if (eatCnt == 0)
    {
        cout << 0 << '\n';
    }

    return 0;
}