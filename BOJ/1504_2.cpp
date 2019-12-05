// 특정한 최단 경로
// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 800 + 1;
const int INF = 987654321;
int N, E;
vector<pair<int, int>> graph[MAX];
vector<int> dijkstra(int start, int end)
{
    vector<int> dist(end + 1, INF); // end 까지 최단거리
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

    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    int first, second;
    cin >> first >> second;

    vector<int> totalRoute = dijkstra(1, N);
    vector<int> route1 = dijkstra(first, N);
    vector<int> route2 = dijkstra(second, N);

    // 1 -> first -> second -> N
    int a = totalRoute[first] + route1[second] + route2[N];
    // 1 -> second -> first -> N
    int b = totalRoute[second] + route2[first] + route1[N];

    int shortRoute = min(a, b);
    if (shortRoute >= INF || shortRoute < 0)
        cout << -1 << '\n';
    else
        cout << shortRoute << '\n';

    return 0;
}