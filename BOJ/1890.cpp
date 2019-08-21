// 점프
// https://www.acmicpc.net/problem/1890
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n;

int board[MAX][MAX];
long long dp[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 0 || (i == n - 1 && j == n - 1))
                continue;

            int dist = board[i][j];
            int down = dist + i;
            int right = dist + j;

            if (down < n)
                dp[down][j] += dp[i][j];

            if (right < n)
                dp[i][right] += dp[i][j];
        }
    }

    cout << dp[n - 1][n - 1] << '\n';
    return 0;
}