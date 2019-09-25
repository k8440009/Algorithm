// 숨바꼭질 2
// https://www.acmicpc.net/problem/12851
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 * 2;
int N, K;
int dist[MAX];
bool visited[MAX];
long long dp[MAX];

int main()
{
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    visited[N] = true;
    dist[N] = 0;
    dp[N] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        int dir[3] = {now - 1, now + 1, now * 2};
        for (int i = 0; i < 3; i++)
        {
            int next = dir[i];
            if (next < 0 || next >= MAX)
                continue;
            // 처음 방문
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
                dist[next] = dist[now] + 1;
                dp[next] = dp[now];
            }
            // 이전에 방문 했고, 최적인 경우
            else if (dist[next] == dist[now] + 1)
            {
                dp[next] += dp[now];
            }
        }
    }

    cout << dist[K] << '\n';
    cout << dp[K] << '\n';
    return 0;
}