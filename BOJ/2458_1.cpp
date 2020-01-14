// 키 순서
// https://www.acmicpc.net/problem/2458
#include <iostream>
#include <algorithm>
using namespace std;
/*
    1. 플로이드 와샬 알고리즘을 이용하여 서로 연결되있는지 체크
    2. (N,Y)와 (Y,N)이 true인 노드의 갯수를 체크하면 노드의 갯수를 알 수 있다.
*/
const int MAX = 500 + 1;
bool dist[MAX][MAX];
int N, M;
void floid()
{
    // (N,Y)와 (Y,M) 가중치 체크
    for (int mid = 1; mid <= N; mid++)
        for (int start = 1; start <= N; start++)
            for (int end = 1; end <= N; end++)
                if (dist[start][mid] && dist[mid][end])
                    dist[start][end] = true;
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        // (N,Y)와 (Y,N)이 true인 노드의 갯수 (서로 연결)
        for (int j = 1; j <= N; j++)
            if (i != j)
                if (dist[i][j] || dist[j][i])
                    cnt++;
        if (cnt == N - 1)
            answer++;
    }
    cout << answer << '\n';
}
void init()
{
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        dist[a][b] = true;
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