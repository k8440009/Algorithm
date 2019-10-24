// 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100 + 1;
const int INF = 987654321;
int N, M;
int dist[MAX];
vector<int> position(MAX);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= 100; i++)
    {
        position[i] = i;
        dist[i] = -1;
    }

    for (int i = 0; i < N + M; i++)
    {
        int x, y;
        cin >> x >> y;
        position[x] = y;
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    int answer = INF;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int dice = 1; dice <= 6; dice++)
        {
            int next = cur + dice;

            if (next > 100)
                continue;

            next = position[next];
            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[100] << '\n';
    return 0;
}