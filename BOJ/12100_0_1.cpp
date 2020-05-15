// 2048 (easy) 4방향 구현
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
    queue<int> q;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (copyBoard[c][r])
                q.push(copyBoard[c][r]);
            copyBoard[c][r] = 0;
        }

        int index = 0;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();

            if (copyBoard[index][r] == 0)
            {
                copyBoard[index][r] = data;
            }
            else if (copyBoard[index][r] == data)
            {
                copyBoard[index][r] *= 2;
                index++;
            }
            else
            {
                index++;
                copyBoard[index][r] = data;
            }
        }
    }
}
void down()
{
    queue<int> q;
    for (int r = 0; r < N; r++)
    {
        for (int c = N - 1; c >= 0; c--)
        {
            if (copyBoard[c][r])
                q.push(copyBoard[c][r]);
            copyBoard[c][r] = 0;
        }

        int index = N - 1;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();

            if (copyBoard[index][r] == 0)
            {
                copyBoard[index][r] = data;
            }
            else if (copyBoard[index][r] == data)
            {
                copyBoard[index][r] *= 2;
                index--;
            }
            else
            {
                index--;
                copyBoard[index][r] = data;
            }
        }
    }
}
void left()
{
    queue<int> q;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (copyBoard[r][c] > 0)
                q.push(copyBoard[r][c]);
            copyBoard[r][c] = 0;
        }

        int index = 0;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();
            // 처음이거나 데이터 값이 9인 경우
            if (copyBoard[r][index] == 0)
            {
                copyBoard[r][index] = data;
            }
            // 데이터 값이 같아서 합치는 경우
            else if (copyBoard[r][index] == data)
            {
                copyBoard[r][index] *= 2;
                index++;
            }
            // 다른경우는 바로 왼쪽 칸에 넣어줌
            else
            {
                index++;
                copyBoard[r][index] = data;
            }
        }
    }
}
void right()
{
    queue<int> q;
    for (int r = 0; r < N; r++)
    {
        for (int c = N - 1; c >= 0; c--)
        {
            if (copyBoard[r][c] > 0)
                q.push(copyBoard[r][c]);
            copyBoard[r][c] = 0;
        }

        int index = N - 1;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();
            // 처음이거나 데이터 값이 9인 경우
            if (copyBoard[r][index] == 0)
            {
                copyBoard[r][index] = data;
            }
            // 데이터 값이 같아서 합치는 경우
            else if (copyBoard[r][index] == data)
            {
                copyBoard[r][index] *= 2;
                index--;
            }
            // 다른경우는 바로 왼쪽 칸에 넣어줌
            else
            {
                index--;
                copyBoard[r][index] = data;
            }
        }
    }
}
void boardCopy()
{
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            copyBoard[r][c] = board[r][c];
}
void dfs(int index, vector<int> &direction)
{
    // 5번 이동했으면 움직인다.
    if (index == 5)
    {
        boardCopy();
        for (int i = 0; i < direction.size(); i++)
        {
            if (direction[i] == 0) // 북
                up();
            else if (direction[i] == 1) // 동
                right();
            else if (direction[i] == 2) // 남
                down();
            else if (direction[i] == 3) // 서
                left();
        }

        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                answer = max(answer, copyBoard[r][c]);
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