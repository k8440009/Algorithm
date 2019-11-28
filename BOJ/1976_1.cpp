// 여행 가자
// https://www.acmicpc.net/problem/1976
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 200;
int N, M;
vector<int> parent(MAX), treeRank(MAX, 1);
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;

    if (treeRank[u] > treeRank[v])
        swap(u, v);
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

    for (int i = 1; i <= N; i++)
        parent[i] = i;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int connect;
            cin >> connect;
            if (connect)
            {
                int parentA = find(i);
                int parentB = find(j);
                if (parentA != parentB)
                    merge(parentA, parentB);
            }
        }
    }
    int root;
    for (int i = 0; i < M; i++)
    {
        int city;
        cin >> city;
        if (i == 0)
            root = find(city);
        else
        {
            if (root != find(city))
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
/*
    참고
    https://jaimemin.tistory.com/770
*/