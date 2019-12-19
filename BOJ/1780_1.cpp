// 종이의 갯수
// https://www.acmicpc.net/problem/1780
#include <bits/stdc++.h>
using namespace std;
const int MAX = 2187;
int N;
int board[MAX][MAX];
int cnt[3];
void dfs(int size, int y, int x)
{
    if (size == 1)
    {
        if (board[y][x] == -1)
            cnt[0] += 1;
        else if (board[y][x] == 0)
            cnt[1] += 1;
        else
            cnt[2] += 1;

        return;
    }

    bool check = true;
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (board[i][j] != board[y][x])
                check = false;
        }
    }

    if (check)
    {
        if (board[y][x] == -1)
            cnt[0] += 1;
        else if (board[y][x] == 0)
            cnt[1] += 1;
        else
            cnt[2] += 1;
    }
    else
    {
        int next = size / 3;

        dfs(next, y, x);
        dfs(next, y, x + next);
        dfs(next, y, x + next * 2);

        dfs(next, y + next, x);
        dfs(next, y + next, x + next);
        dfs(next, y + next, x + next * 2);

        dfs(next, y + next * 2, x);
        dfs(next, y + next * 2, x + next);
        dfs(next, y + next * 2, x + next * 2);
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
            cin >> board[i][j];
    }

    dfs(N, 0, 0);

    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';
    cout << cnt[2] << '\n';
    return 0;
}