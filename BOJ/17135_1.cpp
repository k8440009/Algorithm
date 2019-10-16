// 캐슬 디펜스
// https://www.acmicpc.net/problem/17135
#include <iostream>
using namespace std;
int N, M, D;
const int MAX = 15 + 3;
int board[MAX][MAX];
int practice[MAX][MAX];
void simulate()
{
    int cnt = 0;
    int sum = 0;
    boardCopy();
    while (true)
    {
        if (boardCopy)
            break;
    }
}
void move()
{
    for (int y = N - 1; y >= 0; y--)
    {
        for (int x = 0; x < M; x++)
        {
            // 밖으로 이동
            if (y == N - 1)
                practice[y][x] = 0;
            else
            {
                practice[y + 1][x] = board[y][x];
                practice[y][x] = 0;
            }
        }
    }
}
bool boardCopy()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            practice[y][x] = board[y][x];
        }
    }
}
bool boardCheck()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (practice[y][x] == 1)
                return false;
        }
    }
    return true;
}
void dfs(int index, int cnt)
{
    if (cnt == 3)
    {
        simulate();
        return;
    }

    for (int i = index; i < M; i++)
    {
        board[N][i] = 1;
        dfs(i + 1, cnt + 1);
        board[N][i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
        }
    }

    int answer = 0;
    dfs(0, 0);
    cout << answer << '\n';
    return 0;
}