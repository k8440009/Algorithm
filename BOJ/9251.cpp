// LCS
// https://www.acmicpc.net/problem/9251
/*
    http://melonicedlatte.com/algorithm/2018/03/15/181550.html
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000 + 1;
char a[MAX], b[MAX];
int dp[MAX][MAX];
int main()
{
    int n, m;
    string str1, str2;
    cin >> str1 >> str2;
    n = str1.size();
    m = str2.size();

    for (int i = 0; i < n; i++)
        a[i] = str1[i];

    for (int i = 0; i < m; i++)
        b[i] = str2[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << '\n';
}