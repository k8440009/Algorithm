// 가장 긴 감소하는 부분 수열
// https://www.acmicpc.net/problem/11722
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int dp[MAX + 1];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int answer = dp[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = 1;
        for (int j = n - 1; j >= i; j--)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';

    return 0;
}