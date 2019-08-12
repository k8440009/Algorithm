// N과 M (6)
// https://www.acmicpc.net/problem/15655
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
const int MAX = 8;
int n, m;
bool visited[MAX + 1];
void dfs(int index, int last)
{
    if (index == m)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = index; i < b.size(); i++)
    {
        if (visited[i])
            continue;
        if (last > b[i])
            continue;

        a.push_back(b[i]);
        visited[i] = true;
        dfs(index + 1, b[i]);
        visited[i] = false;
        a.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b.begin(), b.end());

    dfs(0, 0);
    return 0;
}