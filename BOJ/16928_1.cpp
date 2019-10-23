// 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100 + 1;
int N, M;
int dist[MAX];
vector<int> position(MAX);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N + M; i++)
    {
        int x, y;
        cin >> x >> y;
        position[x] = y;
    }

    fill_n(dist, MAX, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == 100)
        {
            cout << dist[cur] << '\n';
            break;
        }

        for (int num = 1; num <= 6; num++)
        {
            int next = cur + num;

            if (next >= MAX)
                continue;

            if (dist[next] == -1)
            {
                if (position[next] != 0)
                {
                    dist[position[next]] = dist[cur] + 1;
                    q.push(position[next]);
                }
                else
                {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
            else if (dist[next] > dist[cur] + 1)
            {
                if (position[next] != 0)
                {
                    if (dist[position[next]] > dist[cur] + 1)
                    {
                        dist[position[next]] = dist[cur] + 1;
                        q.push(position[next]);
                    }
                    else
                    {
                        dist[next] = dist[cur] + 1;
                        q.push(next);
                    }
                }
                else
                {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    return 0;
}