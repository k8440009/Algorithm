// 최단 경로
// https://www.acmicpc.net/problem/1753
/*
    우선 순위 큐 비교연산자
    https://www.acmicpc.net/board/view/37791
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int V, E, K;
vector<vector<pair<int, int>>> adj;
typedef pair<int, int> node;
// 시작점에서 i번째 정점까지의 최단 경로 값을 구한다.
struct cmp
{
    bool operator()(node x, node y)
    {
        // x > y : 오름 차순, x < y : 내림차순
        return x.second > y.second;
    }
};
vector<int> dijkstra(int start)
{
    int n = V + 1;
    // 0 ~ 6까지
    vector<int> distance(n, INF);
    distance[start] = 0; // 시작점에서 시작점은 거리 0
    // 종점과, 가중치(오름차순)
    priority_queue<node, vector<node>, cmp> pq;
    pq.push(make_pair(start, 0)); // 시작점과 초기 비용

    for (int i = 1; i <= n; i++)
    {
        // 우선 순위 큐에 저장
        if (i != start)
            pq.push(make_pair(i, -INF));
    }

    while (!pq.empty())
    {
        int u = pq.top().first;       // 시작점
        int weight = pq.top().second; // 가중치
        pq.pop();

        // 최소거리이면 continue
        if (weight > distance[u])
            continue;

        // 주변 다 확인
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;  // 종점
            int w = adj[u][i].second; // 가중치
            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                pq.push(make_pair(v, distance[v]));
            }
        }
    }
    return distance;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E >> K;
    adj.resize(V + 1);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // 시작점에 종점과 가중치 저장
        adj[u].push_back(make_pair(v, w));
    }
    // 목록 계산
    // 시작점,
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
