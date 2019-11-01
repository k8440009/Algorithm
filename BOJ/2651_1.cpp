// 자동자경주대회
// https://www.acmicpc.net/problem/2651
#include <iostream>
using namespace std;
const int MAX = 100 + 1;
int LIMIT, N;
int dist[MAX + 1];
int station[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> LIMIT >> N; // 최대거리, 정비소갯수
    for (int i = 0; i <= N; i++)
        cin >> dist[i];
    for (int i = 0; i < N; i++)
        cin >> station[i];

    return 0;
}