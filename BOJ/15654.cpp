// N과 M (5)
// https://www.acmicpc.net/problem/15654
#include <bits/stdc++.h>
using namespace std;
const int MAX = 8;
int N, M;
vector<int> a;
vector<int> b;
bool visited[MAX];
void dfs(int index)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << b[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;

        b.push_back(a[i]);
        visited[i] = true;
        dfs(index + 1);
        visited[i] = false;
        b.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    dfs(0);
    return 0;
}