// 경사로
// https://www.acmicpc.net/problem/14890
#include <iostream>
using namespace std;
const int MAX = 100;
int N, L;
int board[MAX][MAX];
bool solve1(int y)
{
    for (int i = 1; i < N; i++)
    {
        if (board[y][i - 1] == board[y][i])
            continue;

        if (abs(board[y][i - 1] - board[y][i]) == 1)
        {
            if (board[y][i - 1] < board[y][i])
            {
                int num = board[y][i - 1];
                for (int j = 0; j < L; j++)
                {
                    if (i - 1 - j < 0)
                        return false;
                    if (board[y][i - 1 - j] != num)
                    {
                        return false;
                    }
                }
            }
            else if (board[y][i - 1] > board[y][i])
            {
                int num = board[y][i];
                for (int j = 0; j < L; j++)
                {
                    if (i + j >= N)
                        return false;
                    if (board[y][i + j] != num)
                    {

                        return false;
                    }
                }

                i += L - 1;
                continue;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool solve2(int x)
{
    for (int i = 1; i < N; i++)
    {
        if (board[i][x] == board[i - 1][x])
            continue;

        if (abs(board[i][x] - board[i - 1][x]) == 1)
        {
            if (board[i][x] > board[i - 1][x])
            {
                int num = board[i - 1][x];
                for (int j = 0; j < L; j++)
                {
                    if (i - 1 - j < 0)
                        return false;
                    if (board[i - 1 - j][x] != num)
                    {
                        return false;
                    }
                }
            }
            else if (board[i - 1][x] > board[i][x])
            {
                int num = board[i][x];
                for (int j = 0; j < L; j++)
                {
                    if (i + j >= N)
                        return false;
                    if (board[i + j][x] != num)
                    {

                        return false;
                    }

                    i += L - 1;
                    continue;
                }
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> N >> L;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (solve1(i))
            cnt++;
        if (solve2(i))
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}