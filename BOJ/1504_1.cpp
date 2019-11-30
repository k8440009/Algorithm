// 특정한 최단 경로
// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 987654321;
const int MAX = 800 + 1;
typedef long long ll;
int N, E;
vector<pair<int, int>> graph[MAX];
vector<int> dijkstra(int start, int end)
{
    vector<int> dist(end, INF);
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
    N++;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    int one, two;
    cin >> one >> two;

    vector<int> result = dijkstra(1, N);
    // one - > N
    vector<int> first = dijkstra(one, N);
    // two -> N
    vector<int> second = dijkstra(two, N);
    // 1 - > Node1 -> Node2 -> N
    ll a = result[one] + first[two] + second[N - 1];
    // 1-> Node2 -> Node1 -> N
    ll b = result[two] + second[one] + first[N - 1];
    ll answer = min(a, b);
    if (answer >= INF || answer < 0)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}