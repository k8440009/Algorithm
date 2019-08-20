// 이동하기
// https://www.acmicpc.net/problem/11048
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000 + 1;

int board[MAX][MAX];
int dp[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }
    dp[1][1] = board[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j + 1 <= m && dp[i][j + 1] < dp[i][j] + board[i][j + 1])
                dp[i][j + 1] = dp[i][j] + board[i][j + 1];
            if (i + 1 <= n && dp[i + 1][j] < dp[i][j] + board[i + 1][j])
                dp[i + 1][j] = dp[i][j] + board[i + 1][j];
            if (i + 1 <= n && j + 1 <= m && dp[i + 1][j + 1] < dp[i][j] + board[i + 1][j + 1])
                dp[i + 1][j + 1] = dp[i][j] + board[i + 1][j + 1];
        }
    }

    cout << dp[n][m];
    return 0;
}