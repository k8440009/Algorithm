// 친구 네트워크
// https://www.acmicpc.net/problem/4195
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 1;
int F;
vector<int> parent(MAX), treeRank(MAX), nodeSize(MAX);
// 유니온 파인드
int find(int u)
{
    if (u == parent[u])
        return u;
    return u = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    if (treeRank[u] > treeRank[v])
        swap(u, v);
    parent[u] = v;
    nodeSize[v] += nodeSize[u];
    if (treeRank[u] == treeRank[v])
        treeRank[v]++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for (int ts = 0; ts < tc; ts++)
    {

        cin >> F;
        // 초기화
        for (int i = 1; i <= MAX; i++)
            parent[i] = i;
        treeRank.assign(MAX, 1), nodeSize.assign(MAX, 1);

        map<string, int> name;
        int index = 1;

        for (int i = 0; i < F; i++)
        {
            string a, b;
            cin >> a >> b;

            // 새로운 이름이라면 인덱스 부여
            if (name.count(a) == 0)
                name[a] = index++;
            if (name.count(b) == 0)
                name[b] = index++;
            // 루트 찾음
            int parentA = find(name[a]);
            int parentB = find(name[b]);
            // 다른 집합이면 합침
            if (parentA != parentB)
                merge(parentA, parentB);

            cout << max(nodeSize[parentA], nodeSize[parentB]) << '\n';
        }
    }

    return 0;
}
