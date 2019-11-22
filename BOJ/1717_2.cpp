// 집합의 표현
// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000 + 1;
int N, M;
vector<int> parent(MAX), treeRank(MAX, 1);
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]); // 경로 압축
}
// u가 속한 트리, v가 속한 트리
void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    // 랭크에 의한 합치기 최적화
    if (treeRank[u] > treeRank[v])
        swap(u, v);
    // rank[v]가 항상 rank[u] 이상이므로 u를 v의 자식으로 넣는다.
    parent[u] = v;
    if (treeRank[u] == treeRank[v])
        treeRank[v]++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // 초기화
    for (int i = 0; i <= N; i++)
        parent[i] = i;

    int op, a, b;
    while (M--)
    {
        cin >> op >> a >> b;
        if (op == 0)
            merge(a, b);
        else if (op == 1)
        {
            int parentA = find(a), parentB = find(b);
            if (parentA == parentB)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}

/*
    참고
    종만북
*/