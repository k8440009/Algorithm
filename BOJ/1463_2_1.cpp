// 1로 만들기 (TopDown)
// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int MAX = 1000000 + 1;
int dp[MAX];

int TopDown(int n)
{
    // 기저
    if (n == 1)
        return 0;
    // 이미 구한 경우
    if (dp[n] != -1)
        return dp[n];

    int result = TopDown(n - 1) + 1;
    if (n % 3 == 0)
        result = min(result, TopDown(n / 3) + 1);
    else if (n % 2 == 0)
        result = min(result, TopDown(n / 2) + 1);
    dp[n] = result;
    return result;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    fill_n(dp, MAX, -1);
    cout << TopDown(N) << '\n';
}