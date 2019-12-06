// 플로이드
// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX = 100 + 1;
int graph[MAX][MAX];
int N, M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    // 플로이드
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            // 초기화 : 자기자신의 가중치는 0, 간선이 없는 경우 아주 큰 값
            graph[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 같은 노선 중 가장 작은 가중치를 가지는 값만 넣는다.
        if (graph[a][b] > c)
            graph[a][b] = c;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            // i,k로 가는 경로가 없다면 for문을 수행 할 필요 없다
            if (graph[i][k] == INF)
                continue;
            else
            {
                for (int j = 1; j <= N; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (graph[i][j] == INF)
                cout << 0 << " ";
            else
                cout << graph[i][j] << " ";
        cout << '\n';
    }

    return 0;
}