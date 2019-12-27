// 외판원 순회
// https://www.acmicpc.net/problem/2098
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 15 + 1, INF = 987654321;
int N, dist[MAX][MAX], cache[MAX][1 << MAX];
// 현재 마을에 있고, visited에 속한 마을을 이미 방문하였을 때, 방문하지 않은 마을들을 순회하여 시작점으로 가는 최단거리
int shortestPath(int current, int visited)
{
    int &ret = cache[current][visited];
    if (ret != -1)
        return ret;
    // 기저 사례 : 모든 마을 방문
    if (visited == (1 << N) - 1)
        return dist[current][0];

    ret = INF;
    for (int next = 0; next < N; next++)
    {
        // 이미 방문했거나, 갈 수 없는 경우 패스
        if (visited & (1 << next) || dist[current][next] == INF)
            continue;
        ret = min(ret, shortestPath(next, visited | (1 << next)) + dist[current][next]);
    }
    return ret;
}
void init()
{
    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
        {
            cin >> dist[y][x];
            if (dist[y][x] == 0)
                dist[y][x] = INF;
        }
    fill_n(cache[0], MAX * (1 << MAX), -1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << shortestPath(0, 1);
    return 0;
}
/*
    참고
    https://kks227.blog.me/
*/