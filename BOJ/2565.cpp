// 전깃줄
// https://www.acmicpc.net/problem/2565
/*
    전깃줄을 없애는 것 보다는
    전깃줄을 추가하면서 안 겹치는 것을 최대로 한다.

    안 겹치는 법
    A 번 기준으로 정렬 한 후 B에서 LIS를 찾는다.
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
int N;
int dp[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    int LIS = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        LIS = max(LIS, dp[i]);
    }

    cout << v.size() - LIS << '\n';

    return 0;
}