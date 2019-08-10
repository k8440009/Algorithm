// N과 M (5)
// https://www.acmicpc.net/problem/15654
#include <bits/stdc++.h>
using namespace std;
const int MAX = 8;
int N, M;
vector<int> a;
vector<int> b;
bool visited[MAX + 1];
void dfs(int index)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < N; i++)
    {
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    dfs(0);
    return 0;
}