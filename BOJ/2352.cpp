// 반도체 설계
// https://www.acmicpc.net/problem/2352
#include <bits/stdc++.h>
using namespace std;
/*
    LIS O(NlongN)
    lowerbound : https://blockdmask.tistory.com/168
    std::lower_bound(A, A+n, k)-A+1은 A배열에서의 상대적 위치(인덱스)
*/
int N;
const int MAX = 40000 + 1;
int dp[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> connect(MAX);
    for (int i = 1; i <= N; i++)
        cin >> connect[i];

    // LIS
    dp[1] = connect[1];
    int size = 1, iter;
    for (int i = 2; i <= N; i++)
    {
        // dp 크기 증가
        if (dp[size] < connect[i])
        {
            size += 1;
            dp[size] = connect[i];
            continue;
        }
        // dp의 최댓값 변경
        iter = lower_bound(dp + 1, dp + size + 1, connect[i]) - dp;
        dp[iter] = connect[i];
    }

    cout << size << '\n';

    return 0;
}