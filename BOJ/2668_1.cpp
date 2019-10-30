// 숫자고르기
// https://www.acmicpc.net/problem/2668
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100 + 1;
int N;
int cnt;

int node[MAX];
bool visited[MAX];
bool cycle[MAX];

bool dfs(int start, int num)
{
    if (visited[num])
        return false;

    visited[num] = true;

    // 사이클을 이루면
    if (start == num || dfs(start, node[num]))
    {
        cnt += 1;
        cycle[num] = true;
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> node[i];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            visited[j] = cycle[j]; // 이미 사이클을 이루는 집합은 재방문 x
        }
        dfs(i, node[i]);
    }

    cout << cnt << '\n';
    for (int i = 1; i <= N; i++)
    {
        if (cycle[i])
            cout << i << '\n';
    }
    return 0;
}