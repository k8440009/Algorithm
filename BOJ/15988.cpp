// 1, 2, 3 더하기 3
// https://www.acmicpc.net/problem/15988
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
const long long MOD = 1000000009;
long long dp[MAX]; // 1 ~ 4
// dp
int main()
{
    // 1
    dp[1] = 1;
    // 2 : 1 + 1, 2
    dp[2] = 2;
    // 3 : 1+1+1, 1 + 2, 2 + 1, 3
    dp[3] = 4;

    for (int i = 4; i <= MAX; i++)
    {
        dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD) + (dp[i - 3] % MOD)) % MOD;
    }

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
    {
        int num;
        cin >> num;
        cout << dp[num] << '\n';
    }

    return 0;
}