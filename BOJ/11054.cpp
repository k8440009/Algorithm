// 가장 긴 바이토닉 부분 수열
// https://www.acmicpc.net/problem/11054
#include <bits/stdc++.h>
using namespace std;
int dp1[1001]; // 앞에서 가장 긴 부분 증가 수열
int dp2[1001]; // 뒤에서 가장 긴 부분 증가 수열
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int MAX = 0;
    // 앞에서부터 세는 가장 긴 부분 증가 수열
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    // 뒤에서 세는 가장 긴 부분 증가 수열
    for (int i = n; i >= 0; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (v[i] > v[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
        MAX = max(MAX, dp1[i] + dp2[i]);
    }
    cout << MAX << '\n';
    return 0;
}