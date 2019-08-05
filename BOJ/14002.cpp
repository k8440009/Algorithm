// 가장 긴 증가하는 부분 수열 4
// https://www.acmicpc.net/problem/14002
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> dp;
vector<int> visited;
// index
void dfs(int index)
{
    if (index == -1)
    {
        return;
    }
    // 다음 인덱스 방문
    dfs(visited[index]);
    cout << a[index] << ' ';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    dp.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        visited[i] = -1; // 마지막 목적지
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                visited[i] = j; // LIS가 갱신된 곳 표시
            }
        }
    }

    int answer = dp[0];
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] > answer)
        {
            answer = dp[i];
            index = i; // LIS 시작 지점
        }
    }
    cout << answer << '\n';

    dfs(index);
    cout << '\n';

    return 0;
}
