// 최단경로
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX = 20000 + 1;
int V, E, K;
vector<pair<int, int>> adj[MAX];
vector<int> dijkstra(int start)
{
    vector<int> dist(V, INF);
    dist[start] = 0; // 자기자신은 가중치 0
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first; // cost를 음수로 바꿔주면, 음수가 작은것이 top으로 온다.
        int here = pq.top().second;
        pq.pop();

        // 만약 지금 꺼낸 경로가 더 짧은 경로를 알고 있는 경우 무시
        if (dist[here] < cost)
            continue;
        // 인접한 정점 모두 검사
        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            // 더 짧은 경로
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

    V++; // 정점은 1부터 시작

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // 그래프 인접 리스트, (연결된 정점번호, 간선 가중치)
        adj[u].push_back(make_pair(v, w));
    }
    vector<int> result = dijkstra(K);
    for (int i = 1; i < V; i++)
    {
        if (result[i] == INF)
            cout << "INF" << '\n';
        else
            cout << result[i] << '\n';
    }
}

/*
    참고
    https://jaimemin.tistory.com/555
*/