// 동물원
// https://www.acmicpc.net/problem/1309
#include <iostream>
using namespace std;
const int MAX = 100000 + 1;
const int MOD = 9901;
int dp[MAX][3];
/*
    참고
    https://mygumi.tistory.com/128
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= N; i++)
    {
        // 사자 배치 없음
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        // 사자 왼쪽 배치
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        // 사자 오른쪽 배치
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
    }

    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD << '\n';

    return 0;
}