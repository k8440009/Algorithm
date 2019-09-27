// 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144
/*
    배열 이동
    4방향 이동
*/
#include <bits/stdc++.h>
using namespace std;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
const int MAX = 50;
int R, C, T;
int upY, upX, downY, downX;
int board[2][MAX][MAX];
void move(int now)
{
    for (int y = upY - 1; y >= 0; y--)
    {
        board[now][y][0] = board[now][y - 1][0];
    }

    for (int x = 0; x < C - 1; x++)
    {
        board[now][0][x] = board[now][0][x + 1];
    }

    for (int y = 0; y < upY; y++)
    {
        board[now][y][C - 1] = board[now][y + 1][C - 1];
    }

    for (int x = C - 1; x > 1; x--)
    {
        board[now][upY][x] = board[now][upY][x - 1];
    }

    board[now][upY][1] = 0;

    for (int y = downY + 1; y < R; y++)
    {
        board[now][y][0] = board[now][y + 1][0];
    }

    for (int x = 0; x < C - 1; x++)
    {
        board[now][R - 1][x] = board[now][R - 1][x + 1];
    }
    for (int y = R - 1; y > downY; y--)
    {
        board[now][y][C - 1] = board[now][y - 1][C - 1];
    }
    for (int x = C - 1; x > 1; x--)
    {
        board[now][downY][x] = board[now][downY][x - 1];
    }

    board[now][downY][1] = 0;
}
void spread(int now)
{
    int next = (now + 1) % 2;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (board[now][r][c] == -1)
                board[next][r][c] = -1;
            else
                board[next][r][c] = 0;
        }
    }

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (board[now][r][c] == -1)
                continue;

            int value = 0;
            int mass = board[now][r][c] / 5;
            for (int dir = 0; dir < 4; dir++)
            {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nc < 0 || nr >= R || nc >= C)
                    continue;
                if (board[next][nr][nc] == -1)
                    continue;

                board[next][nr][nc] += mass;
                value += mass;
            }

            board[next][r][c] += (board[now][r][c] - value);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    upY = -1;

    cin >> R >> C >> T;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> board[0][r][c];
            if (board[0][r][c] == -1)
            {
                if (upY == -1)
                {
                    upY = r;
                    upX = c;
                }
                else
                {
                    downY = r;
                    downX = c;
                }
            }
        }
    }

    int now = 0;
    // 현재 0, next 1
    for (int time = 0; time < T; time++)
    {
        spread(now); // 확산
        now = (now + 1) % 2;
        move(now); // 공기 청정기
    }

    int result = 0;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (board[now][r][c] != -1)
                result += board[now][r][c];
        }
    }

    cout << result << '\n';
    return 0;
}