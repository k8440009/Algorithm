// 플로이드
// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100 + 1;
const int INF = 987654321;
int N, M, dist[MAX][MAX];
void floid()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    // dist 배열은 최단 경로를 담고 있다
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << ((dist[i][j] != INF) ? dist[i][j] : 0) << ' ';
        cout << '\n';
    }
}
void init()
{

    cin >> N >> M;
    fill_n(dist[0], MAX * MAX, INF);
    // dist 배열 초기화
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        // 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
        dist[a][b] = min(dist[a][b], c);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    floid();
    return 0;
}