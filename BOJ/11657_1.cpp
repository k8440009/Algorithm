// 타임머신
// https://www.acmicpc.net/problem/11657
#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX = 500 + 1;
int N, M;
vector<pair<int, int>> graph[MAX];
// 음수 사이클이 있는 경우 텅빈 배열 반환
vector<int> bellmanFord(int start)
{
    vector<int> upper(N + 1, INF);
    upper[start] = 0;

    bool updated;
    for (int node = 1; node <= N; node++)
    {
        updated = false;
        for (int here = 1; here <= N; here++)
        {
            for (int i = 0; i < graph[here].size(); i++)
            {
                int there = graph[here][i].first;
                int cost = graph[here][i].second;
                // (here, there) 간선을 따라 완화 시도
                if (upper[here] != INF && upper[there] > upper[here] + cost)
                {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        // 모든 간선에 대해 완화가 실패했을 경우 V-1도 돌 필요 없이 곧장 종료
        if (!updated)
            break;
    }

    // V번째 순회에서도 완화가 성공했다면 음수 사이클이 있다.
    if (updated)
        upper.clear();

    return upper;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    vector<int> result = bellmanFord(1);

    if (result.empty())
        cout << -1 << '\n';
    else
    {
        for (int i = 2; i < result.size(); i++)
            if (result[i] == INF)
                cout << -1 << '\n';
            else
                cout << result[i] << '\n';
    }

    return 0;
}