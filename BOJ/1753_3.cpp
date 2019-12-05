// 최단경로
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX = 20000 + 1;
vector<pair<int, int>> graph[MAX];
int V, E, K;
vector<int> dijkstra(int start)
{
    vector<int> dist(V + 1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first, here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int i = 0; i < graph[here].size(); i++)
        {
            int there = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;

            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    return dist;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E >> K;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    // 시작점에서 모든 정점의 최단거리
    vector<int> result = dijkstra(K);

    for (int i = 1; i <= V; i++)
    {
        if (result[i] == INF)
            cout << "INF" << '\n';
        else
            cout << result[i] << '\n';
    }

    return 0;
}