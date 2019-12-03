// 미확인 도착지
// https://www.acmicpc.net/problem/9370
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX = 2000 + 1;
vector<pair<int, int>> graph[MAX];
vector<int> dijkstra(int start, int end)
{
    vector<int> dist(MAX, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
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

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        // 교차로, 도로, 목적지 후보 갯수
        int n, m, t;
        // 출발지, 최단 노드 1,2
        int s, g, h;
        cin >> n >> m >> t >> s >> g >> h;
        int cost = 0;
        // 그래프
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back(make_pair(b, d));
            graph[b].push_back(make_pair(a, d));
            if ((a == g && b == h) || (a == h && b == g))
                cost = d;
        }

        vector<int> results;

        for (int i = 0; i < t; i++)
        {
            int endNode;
            cin >> endNode;

            vector<int> totalResult = dijkstra(s, endNode);
            //vector<int> startG = dijkstra(s, g);
            vector<int> endG = dijkstra(g, endNode);
            //vector<int> startH = dijkstra(s, h);
            vector<int> endH = dijkstra(h, endNode);

            int startRoute = totalResult[endNode];

            // START -> G -> H -> END
            int firstRoute = totalResult[g] + cost + endH[endNode];
            // START -> H -> G -> END
            int secondRoute = totalResult[h] + cost + endG[endNode];

            if (startRoute == firstRoute || startRoute == secondRoute)
                results.push_back(endNode);
        }

        sort(results.begin(), results.end());

        for (int i = 0; i < results.size(); i++)
            cout << results[i] << ' ';
        cout << '\n';

        for (int i = 1; i <= n; i++)
            graph[i].clear();
    }
}