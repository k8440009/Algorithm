// 숨바꼭질
// https://www.acmicpc.net/problem/1697
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, m;              // 수빈, 동생
bool visited[MAX + 1]; // 방문 여부
int dist[MAX + 1];     // 몇번 만에 방문했는지

int main()
{
    cin >> n >> m;

    queue<int> q;
    q.push(n);
    visited[n] = true;
    dist[n] = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur - 1 >= 0)
        {
            if (!visited[cur - 1])
            {
                q.push(cur - 1);
                visited[cur - 1] = true;
                dist[cur - 1] = dist[cur] + 1;
            }
        }

        if (cur + 1 < MAX)
        {
            if (!visited[cur + 1])
            {
                q.push(cur + 1);
                visited[cur + 1] = true;
                dist[cur + 1] = dist[cur] + 1;
            }
        }

        if (cur * 2 < MAX)
        {
            if (!visited[cur * 2])
            {
                q.push(cur * 2);
                visited[cur * 2] = true;
                dist[cur * 2] = dist[cur] + 1;
            }
        }
    }

    cout << dist[m] << '\n';

    return 0;
}