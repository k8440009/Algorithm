// 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725
#include <bits/stdc++.h>
using namespace std;
int N;
const int MAX = 100000 + 1;
vector<vector<int>> tree;
int parent[MAX];
bool visited[MAX];
void findParent(int node)
{
    visited[node] = true;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i];

        if (!visited[next])
        {
            parent[next] = node;
            findParent(next);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    tree.resize(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    findParent(1); // 루트 노드

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << '\n';
    }
    /*
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            cout << tree[i][j] << ' ';
        }
        cout << '\n';
    }
*/
    return 0;
}