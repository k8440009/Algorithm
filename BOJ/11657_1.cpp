// 타임머신
// https://www.acmicpc.net/problem/11657
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 500 + 1;
const int INF = 987654321;
int N, M, dist[MAX];
vector<pair<int, int>> adj[MAX];
void bellmanFord(int start)
{
    bool minusCycle = false; // 음수 사이클 체크
    // N-1번 루프, 마지막은 음수 사이클 여부
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            //N-1번의 루프에 걸쳐 각 정점이 i + 1개 정점을 거쳐오는 최단 경로 계산
            for (pair<int, int> p : adj[j])
            {
                int next = p.first, cost = p.second;
                if (dist[j] != INF && dist[next] > dist[j] + cost)
                {
                    dist[next] = dist[j] + cost;
                    // N번째 루프 값이 생신되는 경우 => 음수 사이클
                    if (i == N - 1)
                        minusCycle = true;
                }
            }
        }
    }
    // 음수 사이클 있으면 -1
    if (minusCycle)
        cout << -1 << '\n';
    else
        for (int i = 2; i <= N; i++)
            cout << ((dist[i] != INF) ? dist[i] : -1) << '\n';
}
void init()
{
    cin >> N >> M;
    fill_n(dist, MAX, INF);
    dist[1] = 0;
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    bellmanFord(1);
    return 0;
}