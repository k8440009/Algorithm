// 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095
#include <iostream>
using namespace std;
const int MAX = 11 + 1;
int T, N;
int dp[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    dp[1] = 1, dp[2] = 2, dp[3] = 4;

    for (int i = 4; i < MAX; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}