// 서울 지하철 2호선
// https://www.acmicpc.net/problem/16947
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 3000 + 1;
int N;
bool cycle;
bool cycleStation[MAX];
bool visited[MAX];
vector<int> station[MAX];
int bfs(int node)
{
    fill_n(visited, MAX, 0);
    queue<pair<int, int>> q;
    q.push(make_pair(node, 0));
    visited[node] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cycleStation[cur])
            return cnt;

        for (int i = 0; i < station[cur].size(); i++)
        {
            int next = station[cur][i];

            if (!visited[next])
            {
                visited[next] = true;
                q.push(make_pair(next, cnt + 1));
            }
        }
    }
}
void dfs(int cur, int start, int line)
{
    // 2개 이상이어야 사이클이 생긴다.
    if (cur == start && line >= 2)
    {
        cycle = true;
        return;
    }

    for (int i = 0; i < station[cur].size(); i++)
    {
        int next = station[cur][i];
        // 처음 방문하는 경우
        if (!visited[next])
        {
            visited[next] = true;
            dfs(next, start, line + 1);
        }
        // 이전에 방문한 경우
        else
        {
            // 2개 이상이어야 사이클이 생긴다.
            if (next == start && line >= 2)
            {
                dfs(next, start, line);
            }
        }

        if (cycle)
            return;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        station[a].push_back(b);
        station[b].push_back(a);
    }

    // dfs로 탐색 순환선 여부 체크
    for (int i = 1; i <= N; i++)
    {
        cycle = false;
        fill_n(visited, MAX, 0);
        // 현재역, 부모역, 라인 갯수
        visited[i] = true;
        dfs(i, i, 0);

        if (cycle)
            cycleStation[i] = true;
    }

    // bfs로 역과 순환선의 거리를 구함
    vector<int> answer;
    for (int i = 1; i <= N; i++)
    {
        if (cycleStation[i])
            answer.push_back(0);
        else
            answer.push_back(bfs(i));
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}