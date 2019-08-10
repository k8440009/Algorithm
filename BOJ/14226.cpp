// 이모티콘
// https://www.acmicpc.net/problem/14226
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
// visited[화면에 출력된 갯수][클립보드에 복사된 갯수]
bool visited[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1];

int main()
{
    int n;
    cin >> n;
    // 화면, 클립
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1][0] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        int s = cur.first;
        int c = cur.second;
        q.pop();
        // 복사, 저장 (s,c) -> (s,s)
        if (!visited[s][s])
        {
            q.push({s, s});
            dist[s][s] = dist[s][c] + 1;
            visited[s][s] = true;
        }

        // 붙여넣기 (s,c) -> (s+c,c)
        if (s + c <= n && !visited[s + c][c])
        {
            q.push({s + c, c});
            dist[s + c][c] = dist[s][c] + 1;
            visited[s + c][c] = true;
        }
        // 삭제 (s,c) -> (s-1,c)
        if (s - 1 >= 0 && !visited[s - 1][c])
        {
            q.push({s - 1, c});
            dist[s - 1][c] = dist[s][c] + 1;
            visited[s - 1][c] = true;
        }
    }

    int answer = 0;
    for (int i = 0; i <= n; i++)
    {
        if (answer == 0 || answer > dist[n][i])
            answer = dist[n][i];
    }
    cout << answer << '\n';
    return 0;
}
