// 팰린드롬?
// https://www.acmicpc.net/problem/10942
#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000;
int dp[MAX][MAX];
vector<int> a;
int dfs(int start, int end)
{
    // 기저 사례
    // 길이 1
    if (start == end)
        return 1;
    // 길이2
    else if (start + 1 == end)
    {
        if (a[start] == a[end])
            return 1;
        else
            return 0;
    }

    // 연산
    if (dp[start][end] != -1)
        return dp[start][end];
    if (a[start] != a[end])
        return dp[start][end] = 0;
    else
        return dp[start][end] = dfs(start + 1, end - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    fill_n(dp[0], MAX * MAX, -1);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int start, end;
        cin >> start >> end;
        cout << dfs(start, end) << '\n';
    }

    return 0;
}