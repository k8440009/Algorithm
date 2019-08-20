// N과 M (10)
// https://www.acmicpc.net/problem/15664
#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> a;
vector<int> b;
vector<bool> visited;
vector<vector<int>> answer;

void dfs(int index, int last)
{
    if (index == M)
    {
        vector<int> temp;
        for (int i = 0; i < M; i++)
        {
            temp.push_back(a[i]);
        }
        answer.push_back(temp);

        return;
    }

    for (int i = index; i < N; i++)
    {
        if (visited[i])
            continue;

        if (last > b[i])
            continue;

        a.push_back(b[i]);
        visited[i] = true;
        dfs(index + 1, b[i]);
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
    dfs(0, 0);
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    // & 안쓰면 출력 초과
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