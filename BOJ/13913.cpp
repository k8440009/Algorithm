// 숨바꼭질 4
// https://www.acmicpc.net/problem/13913
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000 + 1;
bool visited[MAX];
int dist[MAX];
int from[MAX]; // 어디에서 왔는지
void print(int n, int k)
{
    if (n != k)
    {
        print(n, from[k]);
    }
    cout << k << ' ';
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = true;
    dist[n] = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        // cur - 1
        if (cur - 1 >= 0)
        {
            if (!visited[cur - 1])
            {
                q.push(cur - 1);
                visited[cur - 1] = true;
                from[cur - 1] = cur;
                dist[cur - 1] = dist[cur] + 1;
            }
        }
        // cur + 1
        if (cur + 1 < MAX)
        {
            if (!visited[cur + 1])
            {
                q.push(cur + 1);
                visited[cur + 1] = true;
                from[cur + 1] = cur;
                dist[cur + 1] = dist[cur] + 1;
            }
        }
        // cur * 2
        if (cur * 2 < MAX)
        {
            if (!visited[cur * 2])
            {
                q.push(cur * 2);
                visited[cur * 2] = true;
                from[cur * 2] = cur;
                dist[cur * 2] = dist[cur] + 1;
            }
        }
    }

    cout << dist[k] << '\n';
    print(n, k);

    return 0;
}