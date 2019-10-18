// 2048 (easy) 4방향 구현
// https://www.acmicpc.net/problem/12100
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 20;
int N, answer;
int board[MAX][MAX];
int copyBoard[MAX][MAX];
void up()
{
    queue<int> q;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (copyBoard[y][x])
                q.push(copyBoard[y][x]);
            copyBoard[y][x] = 0;
        }

        int index = 0;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();

            if (copyBoard[index][x] == 0)
                copyBoard[index][x] = data;
            else if (copyBoard[index][x] == data)
            {
                copyBoard[index][x] *= 2;
                index += 1;
            }
            else
            {
                index += 1;
                copyBoard[index][x] = data;
            }
        }
    }
}
void right()
{
    queue<int> q;
    for (int y = 0; y < N; y++)
    {
        for (int x = N - 1; x >= 0; x--)
        {
            if (copyBoard[y][x])
                q.push(copyBoard[y][x]);
            copyBoard[y][x] = 0;
        }

        int index = N - 1;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();

            if (copyBoard[y][index] == 0)
                copyBoard[y][index] = data;
            else if (copyBoard[y][index] == data)
            {
                copyBoard[y][index] *= 2;
                index -= 1;
            }
            else
            {
                index -= 1;
                copyBoard[y][index] = data;
            }
        }
    }
}
void down()
{
    queue<int> q;
    for (int x = 0; x < N; x++)
    {
        for (int y = N - 1; y >= 0; y--)
        {
            if (copyBoard[y][x])
                q.push(copyBoard[y][x]);
            copyBoard[y][x] = 0;
        }

        int index = N - 1;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();

            if (copyBoard[index][x] == 0)
                copyBoard[index][x] = data;
            else if (copyBoard[index][x] == data)
            {
                copyBoard[index][x] *= 2;
                index -= 1;
            }
            else
            {
                index -= 1;
                copyBoard[index][x] = data;
            }
        }
    }
}
void left()
{
    queue<int> q;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (copyBoard[y][x])
                q.push(copyBoard[y][x]);
            copyBoard[y][x] = 0;
        }

        int index = 0;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();

            if (copyBoard[y][index] == 0)
                copyBoard[y][index] = data;
            else if (copyBoard[y][index] == data)
            {
                copyBoard[y][index] *= 2;
                index += 1;
            }
            else
            {
                index += 1;
                copyBoard[y][index] = data;
            }
        }
    }
}
void boardCopy()
{
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            copyBoard[y][x] = board[y][x];
}
void dfs(int index, vector<int> &direction)
{

    if (index == 5)
    {
        boardCopy();
        for (int i = 0; i < direction.size(); i++)
        {
            if (direction[i] == 0)
                up();
            else if (direction[i] == 1)
                right();
            else if (direction[i] == 2)
                down();
            else if (direction[i] == 3)
                left();
        }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                answer = max(answer, copyBoard[y][x]);
            }
        }
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

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
        }
    }

    vector<int> direction;
    answer = 0;
    dfs(0, direction);
    cout << answer << '\n';

    return 0;
}