// 합분해
// https://www.acmicpc.net/problem/2225
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000;
const int MAX = 200 + 1;
int dp[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    /*
        1 1

        20 2
        0 + 20
        1 + 19
        2 + 18
        ~
        20 + 0

        

    */
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j == 1)
                dp[i][j] = 1;
            dp[i][j] = dp[i][j - 1] + 1;
        }
    }

    cout << dp[N][K];
    return 0;
}