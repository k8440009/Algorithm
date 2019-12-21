// 정수 삼각형
// https://www.acmicpc.net/problem/1932
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500 + 1;
int N, triangle[MAX][MAX];
int cache[MAX][MAX];
// (y,x) 위치에서 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합 반환
int path(int y, int x)
{
    //기저
    if (y == N - 1)
        return triangle[y][x];
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill_n(cache[0], MAX * MAX, -1);
    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x <= y; x++)
            cin >> triangle[y][x];
    cout << path(0, 0) << '\n';
    return 0;
}