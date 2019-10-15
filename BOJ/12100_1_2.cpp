// 2048 (easy)
// https://www.acmicpc.net/problem/12100
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, answer;
struct BOARD
{
    int board[20][20];

    void rotate()
    {
        int temp[20][20];
        // 90도 회전
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                temp[y][x] = board[N - x - 1][y];
            }
        }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                board[y][x] = temp[y][x];
            }
        }
    }

    int getMax()
    {
        int result = 0;

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (result < board[y][x])
                    result = board[y][x];
            }
        }

        return result;
    }

    void up()
    {
        int temp[20][20];

        for (int x = 0; x < N; x++)
        {
            int flag = 0, target = -1;
            for (int y = 0; y < N; y++)
            {
                if (board[y][x] == 0)
                {
                    continue;
                }

                if (flag == 1 && board[y][x] == temp[target][x])
                {
                    temp[target][x] *= 2, flag = 0;
                }
                else
                {
                    temp[++target][x] = board[y][x], flag = 1;
                }
            }

            for (++target; target < N; ++target)
            {
                temp[target][x] = 0;
            }
        }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                board[y][x] = temp[y][x];
            }
        }
    }
};
const int MAX = 20;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int board[MAX][MAX];
void dfs(BOARD cur, int count)
{
    if (count == 5)
    {
        int candi = cur.getMax();
        if (answer < candi)
        {
            answer = candi;
        }
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        BOARD next = cur;
        next.up();
        dfs(next, count + 1);
        cur.rotate();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    BOARD Board;
    cin >> N;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> Board.board[y][x];
        }
    }

    answer = 0;
    dfs(Board, 0);
    cout << answer << '\n';

    return 0;
}
