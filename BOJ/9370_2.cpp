// 미확인 도착지
// https://www.acmicpc.net/problem/9370
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX = 2000 + 1;
vector<pair<int, int>> graph[MAX];
int N, M, T;
vector<int> dijkstra(int start)
{
    vector<int> dist(N + 1, INF);
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
            int nextDist = graph[here][i].second + cost;

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
        int s, g, h, cost;
        cin >> N >> M >> T >> s >> g >> h;
        for (int i = 0; i < M; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back(make_pair(b, d));
            graph[b].push_back(make_pair(a, d));

            if ((a == g && b == h) || (a == h && b == g))
                cost = d;
        }

        vector<int> results;

        for (int i = 0; i < T; i++)
        {
            int destination;
            cin >> destination;

            vector<int> result = dijkstra(s);
            vector<int> route1 = dijkstra(g);
            vector<int> route2 = dijkstra(h);
            // 1 -> g -> h -> T
            int firstRoute = result[g] + cost + route2[destination];
            // 1 -> h -> g - >T
            int secondRoute = result[h] + cost + route1[destination];

            if (result[destination] == firstRoute || result[destination] == secondRoute)
                results.push_back(destination);
        }

        sort(results.begin(), results.end());

        for (int i = 0; i < results.size(); i++)
            cout << results[i] << ' ';
        cout << '\n';

        for (int i = 1; i <= N; i++)
            graph[i].clear();
    }

    return 0;
}