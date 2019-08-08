// 카드 구매
// https://www.acmicpc.net/problem/11052
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int dp[MAX + 1]; // i에서의 최대값
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; // 카드의 갯수
    cin >> n;

    vector<int> card(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> card[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            // 최대 가격을 구한다.
            dp[i] = max(dp[i], card[j] + dp[i - j]);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}