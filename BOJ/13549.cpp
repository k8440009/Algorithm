// 숨바꼭질 3
// https://www.acmicpc.net/problem/13549
#include <bits/stdc++.h>
using namespace std;
/*
    참고
    https://www.acmicpc.net/board/view/38887
*/
const int MAX = 100000 + 1;
int dist[MAX];
bool visited[MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;
    visited[n] = true;

    while (!dq.empty())
    {
        auto cur = dq.front();
        dq.pop_front();

        if (cur * 2 <= MAX)
        {
            if (!visited[cur * 2])
            {
                dq.push_front(cur * 2);
                dist[cur * 2] = dist[cur];
                visited[cur * 2] = true;
            }
        }

        if (cur + 1 <= MAX)
        {
            if (!visited[cur + 1])
            {
                dq.push_back(cur + 1);
                dist[cur + 1] = dist[cur] + 1;
                visited[cur + 1] = true;
            }
        }

        if (cur - 1 >= 0)
        {
            if (!visited[cur - 1])
            {
                dq.push_back(cur - 1);
                dist[cur - 1] = dist[cur] + 1;
                visited[cur - 1] = true;
            }
        }
    }

    cout << dist[m] << '\n';
    return 0;
}
