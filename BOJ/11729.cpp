// 하노이 탑 이동 순서
// https://www.acmicpc.net/problem/11729
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> result;
void dfs(int n, int from, int by, int to)
{
    if (n == 1)
    {
        result.push_back({from, to});
    }
    else
    {
        // b->c
        dfs(n - 1, from, to, by);
        result.push_back({from, to});
        dfs(n - 1, by, from, to);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    dfs(n, 1, 2, 3);
    cout << result.size() << '\n';
    for (auto iter : result)
    {
        cout << iter.first << ' ' << iter.second << '\n';
    }
    return 0;
}