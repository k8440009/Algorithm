// 쿼드 트리
// https://www.acmicpc.net/problem/1992
#include <bits/stdc++.h>
using namespace std;
const int MAX = 64;

int N;
int board[MAX][MAX];

void dfs(int n, int y, int x)
{
    // 기저 사례
    if (n == 1)
    {
        cout << board[y][x];
        return;
    }

    bool zero = true, one = true;

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (board[i][j] == 1)
                zero = false;
            else if (board[i][j] == 0)
                one = false;
        }
    }

    if (zero)
        cout << 0;
    else if (one)
        cout << 1;
    else
    {
        cout << '(';
        int half = n / 2;
        dfs(half, y, x);               // 1사분면
        dfs(half, y, x + half);        // 2사분면
        dfs(half, y + half, x);        // 3사분면
        dfs(half, y + half, x + half); // 4사분면
        cout << ')';
    }

    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = s[j] - '0';
        }
    }

    dfs(N, 0, 0);
    cout << '\n';
    return 0;
}