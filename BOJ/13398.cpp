// 연속합 2
// https://www.acmicpc.net/problem/13398
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;
int N;

int dp[2][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<int> a(N + 2);
    for (int i = 2; i <= N + 1; i++)
        cin >> a[i];

    int answer = INT_MIN;
    // dp[0][i] = max(dp[0][i-1] + a[i], a[i])
    // dp[1][i] = max(dp[0][i-2] + a[i], dp[1][i-1] + a[i])
    for (int i = 2; i <= N + 1; i++)
    {
        dp[0][i] = max(dp[0][i - 1] + a[i], a[i]);
        dp[1][i] = max(dp[0][i - 2] + a[i], dp[1][i - 1] + a[i]);

        answer = max(answer, dp[0][i]);
        answer = max(answer, dp[1][i]);
    }

    cout << answer << '\n';

    return 0;
}