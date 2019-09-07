// 배열 돌리기 1
// https://www.acmicpc.net/problem/16926
#include <iostream>
using namespace std;
const int MAX = 300;
int N, M, R;
int stand; // 기준
int board[MAX][MAX], copyBoard[MAX][MAX];
bool visited[MAX][MAX];
void dfs(int x, int y, int dir, int r, int range, int origin)
{
    if (r == R)
    {
        copyBoard[x][y] = origin;
        return;
    }
    // 동쪽
    if (dir == 0)
    {
        if (y + 1 < M - range)
            dfs(x, y + 1, dir, r + 1, range, origin);
        else
            dfs(x - 1, y, 3, r + 1, range, origin);
    }
    // 서쪽
    else if (dir == 1)
    {
        if (y - 1 >= range)
            dfs(x, y - 1, dir, r + 1, range, origin);
        else
            dfs(x + 1, y, 2, r + 1, range, origin);
    }
    // 남쪽
    else if (dir == 2)
    {
        if (x + 1 < N - range)
            dfs(x + 1, y, dir, r + 1, range, origin);
        else
            dfs(x, y + 1, 0, r + 1, range, origin);
    }
    // 북쪽
    else if (dir == 3)
    {
        if (x - 1 >= range)
            dfs(x - 1, y, dir, r + 1, range, origin);
        else
            dfs(x, y - 1, 1, r + 1, range, origin);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    // 삽입
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    if (N > M)
        stand = M / 2;
    else
        stand = N / 2;

    for (int rotate = 0; rotate < stand; rotate++)
    {
        int x = rotate;
        int y = rotate;

        for (int i = x; i < N - stand; i++)
        {
            if (!visited[i][y])
            {
                dfs(i, y, 2, 0, rotate, board[i][y]);
                visited[i][y] = true;
            }
        }

        for (int i = y; i < M - stand; i++)
        {
            if (!visited[N - 1 - rotate][i])
            {
                dfs(N - 1 - rotate, i, 0, 0, rotate, board[N - 1 - rotate][i]);
                visited[N - 1 - rotate][i] = true;
            }
        }

        for (int i = N - 1 - stand; i >= stand; i++)
        {
            if (!visited[i][M - 1 - rotate])
            {
                dfs(i, M - 1 - rotate, 3, 0, rotate, board[i][M - 1 - rotate]);
                visited[N - 1 - rotate][i] = true;
            }
        }

        for (int i = M - 1 - stand; i >= stand; i++)
        {
            if (!visited[x][i])
            {
                dfs(x, i, 1, 0, rotate, board[x][i]);
                visited[x][i] = true;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << copyBoard[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
