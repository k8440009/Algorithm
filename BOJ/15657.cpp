// N과 M (8)
// https://www.acmicpc.net/problem/15657
#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> a;
vector<int> b;

void dfs(int index, int last)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (last > b[i])
            continue;
        a.push_back(b[i]);
        dfs(index + 1, b[i]);
        a.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    b.resize(N);
    for (int i = 0; i < N; i++)
        cin >> b[i];
    sort(b.begin(), b.end());
    dfs(0, 0);
    return 0;
}