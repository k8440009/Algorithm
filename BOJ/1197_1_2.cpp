// 최소 스패닝 트리 (프림)
// https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 10000 + 1;
const int INF = 987654321;
// 정점과 간선
int V, E;
// 그래프 인접 리스트 (연결된 정점 번호, 간선 가중치)
vector<pair<int, int>> graph[MAX];
// 해당 정점이 트리에 포함 되어 있는가?
vector<bool> added(MAX);
// 가중치 합 반환
long long prim()
{
    int result = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 가중치, 노드
    pq.push(make_pair(0, 1));

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (added[here])
            continue;
        added[here] = true;

        result += cost;

        for (int i = 0; i < graph[here].size(); i++)
        {
            int there = graph[here][i].first;
            int nextDist = graph[here][i].second;

            if (!added[there])
                pq.push(make_pair(nextDist, there));
        }
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
        graph[b].push_back(make_pair(a, c));
    }

    cout << prim() << '\n';

    return 0;
}