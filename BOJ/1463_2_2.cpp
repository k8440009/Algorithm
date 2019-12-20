// 1로 만들기 (BottomUp)
// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000000 + 1;
int N;
int dp[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill_n(dp, MAX, MAX);
    cin >> N;
    dp[1] = 0; // 기저
    for (int i = 1; i < N; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i * 2 < MAX)
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if (i * 3 < MAX)
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }

    cout << dp[N] << '\n';

    return 0;
}