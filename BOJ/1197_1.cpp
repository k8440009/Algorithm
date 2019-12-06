// 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000 + 1;
// 유니온 파인드
struct DisjointSet
{
    vector<int> parent;
    DisjointSet(int n) : parent(n + 1)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
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
        if (u < v)
            swap(u, v);
        parent[u] = v;
    }
};
// 정점과 간선
int V, E;
// 그래프 인접 리스트 (연결된 정점 번호, 간선 가중치)
vector<pair<int, int>> graph[MAX];
// vector<int> select(MAX);
// 주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선목록을 select에 저장하고
// 가중치의 합을 반환한다.
int kruskal()
{
    int result = 0;
    // (가중치, (정점1, 정점2)) 목록을 얻는다.
    vector<pair<int, pair<int, int>>> edges;
    for (int u = 1; u <= V; u++)
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first, cost = graph[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    // 가중치 순으로 정렬
    sort(edges.begin(), edges.end());

    // 처음에는 모든 정점이 분리되어 있다.
    DisjointSet sets(V);

    for (int i = 0; i < edges.size(); i++)
    {
        // 간선 (u,v) 검사
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        // 이미 u,v가 연결되어 있는 경우 무시
        if (sets.find(u) == sets.find(v))
            continue;
        // 연결되어 있지 않은 경우 합친다
        sets.merge(u, v);
        // select.push_back(make_pair(u, v));
        result += cost;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    cout << kruskal() << '\n';

    return 0;
}