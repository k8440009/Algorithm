// 서울 지하철 2호선
// https://www.acmicpc.net/problem/16947
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 3000 + 1;
int N;
bool cycle;
bool visited[MAX];
bool stationCycle[MAX];
vector<int> station[MAX];
vector<int> answer;
int bfs(int node)
{
    fill_n(visited, MAX, false);
    queue<pair<int, int>> q;
    q.push(make_pair(node, 0)); // 현재 노드, 라인 갯수
    visited[node] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (stationCycle[cur])
        {
            return cnt;
        }

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
    // 시작점에 돌아오고, line이 2개 이상인 경우
    if (cur == start && line >= 2)
    {
        cycle = true;
        return;
    }

    visited[cur] = true;
    // 현재 역의 모든 노드 탐색
    for (int i = 0; i < station[cur].size(); i++)
    {
        int next = station[cur][i];
        // 다음 노드 방문 하지 않은 경우
        if (!visited[next])
        {
            dfs(next, start, line + 1);
        }
        // 다음 노드 방문 한 경우
        else
        {
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
    // 모든 역 방문하면서 dfs로 순환선 체크
    for (int i = 1; i <= N; i++)
    {
        fill_n(visited, MAX, 0);
        cycle = false;

        int start = i;
        dfs(i, start, 0); // 현재, 시작역, line 갯수
        // 사이클 있으면
        if (cycle)
            stationCycle[i] = true;
    }

    for (int i = 1; i <= N; i++)
    {
        // 순환선에 있으면
        if (stationCycle[i])
        {
            // 거리 0
            answer.push_back(0);
            continue;
        }
        // 아닌 경우
        else
        {
            // bfs를 사용하여 순환선과 역의 최단거리를 구한다.
            int dist = bfs(i);
            answer.push_back(dist);
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';
    cout << '\n';

    return 0;
}