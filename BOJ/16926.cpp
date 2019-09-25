// 배열 돌리기 1
// https://www.acmicpc.net/problem/16926
#include <bits/stdc++.h>
using namespace std;
int N, M, R, CNT;
const int MAX = 300;
// 반시계
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int board[MAX][MAX];
void rotateBoard()
{
    for (int i = 0; i < CNT; i++)
    {
        int temp = board[i][i];

        int dir = 0;
        int y = i;
        int x = i;

        while (dir < 4)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            // 범위에 벗어 날 때 까지 옮기고 범위 밖에 도달하면 꺽는다.
            if (ny >= i && nx >= i && ny < N - i && nx < M - i)
            {
                board[y][x] = board[ny][nx];
                y = ny;
                x = nx;
            }
            else
                dir += 1;
        }

        board[i + 1][i] = temp;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    CNT = min(N, M) / 2;

    for (int i = 0; i < R; i++)
        rotateBoard();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    return 0;
}