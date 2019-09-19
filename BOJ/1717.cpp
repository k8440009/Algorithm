// 집합의 표현 (유니온 파인드)
// https://www.acmicpc.net/problem/1717
#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> level;

int find(int u)
{
    // 루트 노드이면 되돌려줌
    if (u == parent[u])
        return u;
    // 그 외는 자신의 루트 탐색
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);

    // 루트가 같다면 이미 같은 트리
    if (u == v)
        return;
    // u가 v보다 더 깊은 트리면 swap
    if (level[u] > level[v])
        swap(u, v);
    // u이 루트가 v가 되도록
    parent[u] = v;
    // u와 v의 깊이 가 같을 때 까지 v의 깊이를 늘려준다.
    if (level[u] == level[v])
        ++level[v];
}
int main()
{
    int n, m;
    cin >> n >> m;
    // 초기에는 자신의 부모는 자기 자신
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        level[i] = 1;
    }

    while (m--)
    {
        int command;
        cin >> command;

        // Union : 합집합
        if (command == 0)
        {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        // u와 v를 find 후 루트 비교
        else if (command == 1)
        {
            int u, v;
            cin >> u >> v;
            u = find(u);
            v = find(v);

            u == v ? cout << "Yes" << '\n' : cout << "No" << '\n';
        }
    }
}
