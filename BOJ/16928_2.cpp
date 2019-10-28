// 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100 + 1;
const int INF = 987654321;
int N, M;
int board[MAX];
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
        board[i] = i;
        dist[i] = INF;
    }

    for (int i = 0; i < N + M; i++)
    {
        int a, b;
        cin >> a >> b;
        position[a] = b;
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == 100)
        {
            cout << dist[100] << '\n';
            break;
        }
        // 사다리나 뱀이 존재하는 경우
        if (position[cur] > 0)
        {
            if (dist[position[cur]] > dist[cur])
            {
                dist[position[cur]] = dist[cur];
                q.push(position[cur]);
            }
        }
        else
        {
            for (int dice = 1; dice <= 6; dice++)
            {
                int next = cur + dice;

                if (next >= MAX)
                    continue;

                if (dist[next] > dist[cur] + 1)
                {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    return 0;
}