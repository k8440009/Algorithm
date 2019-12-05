// 웜홀
// https://www.acmicpc.net/problem/1865
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX = 500 + 1;
int N, M, W;
vector<pair<int, int>> graph[MAX];
// 시작점에서 목표로가는 최단 거리 계산
bool bellman(int start)
{
    vector<int> upper(N + 1, INF);
    upper[start] = 0;
    // N-1번 순회
    for (int node = 1; node <= N; node++)
    {
        for (int here = 1; here <= N; here++)
        {
            for (int i = 0; i < graph[here].size(); i++)
            {
                int there = graph[here][i].first;
                int cost = graph[here][i].second;
                if (upper[here] != INF && upper[here] + cost < upper[there])
                {
                    upper[there] = upper[here] + cost;
                    if (node == N)
                        return true;
                }
            }
        }
    }

    return false;
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
        cin >> N >> M >> W;
        int s, e, t;
        // 입력
        for (int i = 0; i < M + W; i++)
        {
            cin >> s >> e >> t;
            if (i > M - 1)
                graph[s].push_back(make_pair(e, -t));
            else
            {
                graph[s].push_back(make_pair(e, t));
                graph[e].push_back(make_pair(s, t));
            }
        }
        /*
            체크해야할 것
            1. 음수 사이클이 존재하는가?
            2. 시작점으로 돌아올 수 있는가? => 양방향 그래프라 생각 해줄 필요 없다.
        */
        if (bellman(1))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        // 초기화
        for (int i = 1; i <= N; i++)
            graph[i].clear();
    }
}