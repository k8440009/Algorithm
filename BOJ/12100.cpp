// 2048 (easy)
// https://www.acmicpc.net/problem/12100
#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int board[MAX][MAX];
int copyBoard[MAX][MAX];
int N;
int answer;

void up()
{
    for (int row = 1; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (copyBoard[row][col] == 0)
                continue;

            int r = row;
            while (r - 1 >= 0)
            {
                if (copyBoard[r - 1][col] == 0)
                {
                    copyBoard[r - 1][col] = copyBoard[r][col];
                    copyBoard[r][col] = 0;
                }
                else if (copyBoard[r - 1][col] == copyBoard[r][col])
                {
                    copyBoard[r - 1][col] *= 2;
                }

                r -= 1;
            }
        }
    }
}
void down()
{
    for (int row = N - 1; row >= 0; row--)
    {
        for (int col = 0; col < N; col++)
        {
            if (copyBoard[row][col] == 0)
                continue;

            int r = row;
            while (r + 1 < N)
            {
                if (copyBoard[r + 1][col] == 0)
                {
                    copyBoard[r + 1][col] = copyBoard[r][col];
                    copyBoard[r][col] = 0;
                }
                else if (copyBoard[r + 1][col] == copyBoard[r][col])
                {
                    copyBoard[r + 1][col] *= 2;
                }

                r += 1;
            }
        }
    }
}
void left()
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 1; col < N; col++)
        {
            if (copyBoard[row][col] == 0)
                continue;

            int c = col;
            while (c - 1 >= 0)
            {
                if (copyBoard[row][c - 1] == 0)
                {
                    copyBoard[row][c - 1] = copyBoard[row][c];
                    copyBoard[row][c] = 0;
                }
                else if (copyBoard[row][c - 1] == copyBoard[row][c])
                {
                    copyBoard[row][c - 1] *= 2;
                }

                c -= 1;
            }
        }
    }
}
void right()
{
    for (int row = 0; row < N; row++)
    {
        for (int col = N - 1; col >= 0; col--)
        {
            if (copyBoard[row][col] == 0)
                continue;

            int c = col;
            while (c + 1 < N)
            {
                if (copyBoard[row][c + 1] == 0)
                {
                    copyBoard[row][c + 1] = copyBoard[row][c];
                    copyBoard[row][c] = 0;
                }
                else if (copyBoard[row][c + 1] == copyBoard[row][c])
                {
                    copyBoard[row][c + 1] *= 2;
                }

                c += 1;
            }
        }
    }
}
void findMax()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //cout << board[i][j] << ' ';
            answer = max(answer, copyBoard[i][j]);
        }
        //cout << '\n';
    }
    //cout << '\n';
}
void boardCopy()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            copyBoard[i][j] = board[i][j];
        }
    }
}
void dfs(int index, vector<int> &direction)
{

    // 5번 이동했으면 움직인다.
    if (index == 5)
    {
        boardCopy();
        for (int i = 0; i < direction.size(); i++)
        {
            // 북
            if (direction[i] == 0)
                up();
            // 동
            else if (direction[i] == 1)
                right();

            // 남
            else if (direction[i] == 2)
                down();
            // 서
            else if (direction[i] == 3)
                left();
        }

        findMax();
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        direction.push_back(dir);
        dfs(index + 1, direction);
        direction.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<int> direction;
    answer = 0;
    dfs(0, direction);
    cout << answer << '\n';
    return 0;
}