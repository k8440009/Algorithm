// 피보나치 함수
// https://www.acmicpc.net/problem/1003
#include <bits/stdc++.h>
using namespace std;
const int MAX = 39 + 1;
int dp[MAX][2]; // 각 0과 1 체크
#define rep2(i, a, b) for (int i = a; i <= b; i++)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    dp[0][0] = 1; // fibo(0)
    dp[1][1] = 1; // fibo(1)
    // fibo(n) = fibo(n-1) + fibo(n-2)
    rep2(i, 2, MAX)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    // 출력
    while (test_case--)
    {
        int n;
        cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << '\n';
    }
    return 0;
}