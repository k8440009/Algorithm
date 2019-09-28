// 배열 돌리기 1
// https://www.acmicpc.net/problem/16926
#include <bits/stdc++.h>
using namespace std;
const int MAX = 300;
int N, M, R;
int board[2][MAX][MAX];
void rotateBoard(int now, int y, int x, int cnt)
{
    int next = (now + 1) % 2;

    int temp = board[now][y][x];

    for (int r = y + 1; r < N - cnt; r++)
        board[next][r][x] = board[now][r - 1][x];
    for (int c = x + 1; c < M - cnt; c++)
        board[next][N - 1 - cnt][c] = board[now][N - 1 - cnt][c - 1];
    for (int r = N - 1 - cnt; r - 1 >= y; r--)
        board[next][r - 1][M - 1 - cnt] = board[now][r][M - 1 - cnt];
    for (int c = M - 1 - cnt; c - 1 >= x; c--)
        board[next][y][c - 1] = board[now][y][c];
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
        {
            cin >> board[0][i][j];
        }
    }

    int now = 0;
    int mod = min(N, M) / 2;
    int y = 0;
    int x = 0;

    for (int t = 0; t < R; t++)
    {
        for (int i = 0; i < mod; i++)
        {
            rotateBoard(now, y + i, x + i, i);
        }
        now = (now + 1) % 2;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[now][i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
