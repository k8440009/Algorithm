// 쉬운 계단 수 https://www.acmicpc.net/problem/10844
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 + 1;
int N;
int dp[MAX];
int a[MAX];
int main()
{
    cin >> N;

    dp[0] = 0;
    for (int i = 1; i < MAX; i++)
    {
        dp[i] = max(dp[i - 1] + 1, dp[i]);
    }
    return 0;
}