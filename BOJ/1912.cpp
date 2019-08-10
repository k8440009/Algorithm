// 연속합
// https://www.acmicpc.net/problem/1912
#include <bits/stdc++.h>
using namespace std;
const long long INF = 987654321;
const int MAX = 100000;
int N;
vector<long long> a;
long long dp[MAX + 1];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = a[i];

        if (i == 0)
        {
            answer = dp[0];
            continue;
        }
        if (dp[i] < dp[i - 1] + a[i])
            dp[i] = dp[i - 1] + a[i];

        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';

    return 0;
}