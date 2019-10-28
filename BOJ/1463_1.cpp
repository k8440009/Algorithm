// 1로 만들기
// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000000 + 1;
const int INF = 987654321;
int N;
int dp[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    fill_n(dp, MAX, INF);
    dp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        //
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[N] << '\n';

    return 0;
}