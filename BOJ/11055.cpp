// 가장 큰 증가 부분 수열
// https://www.acmicpc.net/problem/11055
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

    int answer = a[0];
    for (int i = 0; i < n; i++)
    {
        dp[i] = a[i];
        for (int j = 0; j <= i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';

    return 0;
}