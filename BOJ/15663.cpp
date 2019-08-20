// N과 M (9)
// https://www.acmicpc.net/problem/15663
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a;
vector<int> b;
vector<int> visited;
vector<vector<int>> answer;
void dfs(int index)
{
    if (index == M)
    {
        vector<int> temp;
        for (int i = 0; i < M; i++)
            temp.push_back(a[i]);

        answer.push_back(temp);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;

        a.push_back(b[i]);
        visited[i] = true;
        dfs(index + 1);
        a.pop_back();
        visited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    b.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++)
        cin >> b[i];

    sort(b.begin(), b.end());
    dfs(0);
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for (auto &v : answer)
    {
        for (int i = 0; i < M; i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}