// 배열 돌리기 1
// https://www.acmicpc.net/problem/16926
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 300 + 1;
int N, M, R;
int board[2][MAX][MAX];
void rotate(int now, int sy, int sx, int ey, int ex)
{
    int next = (now + 1) % 2;
    int temp = board[now][sy][sx];
    // 위
    for (int x = sx; x + 1 <= ex; x++)
        board[next][sy][x] = board[now][sy][x + 1];
    // 오른쪽
    for (int y = sy; y + 1 <= ey; y++)
        board[next][y][ex] = board[now][y + 1][ex];
    // 아래
    for (int x = ex; x - 1 >= sx; x--)
        board[next][ey][x] = board[now][ey][x - 1];
    // 왼쪽
    for (int y = ey; y - 1 >= sy; y--)
        board[next][y][sx] = board[now][y - 1][sx];

    board[next][sy + 1][sx] = temp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[0][y][x];
        }
    }

    int now = 0;
    int position = min(M, N) / 2;
    int sy = 0, sx = 0, ey = N - 1, ex = M - 1;

    for (int cnt = 0; cnt < R; cnt++)
    {
        for (int i = 0; i < position; i++)
        {
            rotate(now, sy + i, sx + i, ey - i, ex - i);
        }
        now = (now + 1) % 2;
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cout << board[now][y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}