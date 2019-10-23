// 타일 채우기
// https://www.acmicpc.net/problem/2133
#include <iostream>
using namespace std;
const int MAX = 30 + 1;
int dp[MAX];
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    dp[0] = 1, dp[1] = 0, dp[2] = 3;

    if (N % 2 == 0)
    {
        for (int i = 4; i <= N; i += 2)
        {
            dp[i] = dp[i - 2] * 3;

            for (int j = 4; i - j >= 0; j += 2)
            {
                dp[i] += dp[i - j] * 2;
            }
        }
    }

    cout << dp[N] << '\n';

    return 0;
}