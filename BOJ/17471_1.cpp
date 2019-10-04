// 게리맨더링
// https://www.acmicpc.net/problem/17471
#include <bits/stdc++.h>
using namespace std;
const int MAX = 11;
const int INF = 987654321;
int N, answer;
vector<vector<int>> graph;
vector<int> people;
bool bfs(int index, int team[])
{
    bool visited[MAX];
    fill_n(visited, N, 0);

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (index == team[i])
        {
            q.push(i);
            visited[i] = true;
            break;
        }
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (visited[i] || index != team[i])
                continue;

            for (int j = 0; j < graph[now].size(); j++)
            {
                if (graph[now][j] == i)
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (index != team[i])
            continue;
        if (!visited[i])
            return false;
    }
    return true;
}
void setTeam(int index, int team[])
{
    if (index == N)
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (team[i] == 0)
                cnt += 1;
        }
        /*
        if (cnt == 0 || cnt == N)
            return;
        */

        if (bfs(0, team) && bfs(1, team))
        {
            int zero = 0, one = 0;
            for (int i = 0; i < N; i++)
            {
                if (team[i] == 0)
                    zero += people[i];
                else
                    one += people[i];
            }

            answer = min(answer, abs(zero - one));
            return;
        }

        return;
    }

    team[index] = 1;
    setTeam(index + 1, team);
    team[index] = 0;
    setTeam(index + 1, team);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // 인구
    people.resize(N);
    graph.resize(N);
    for (int i = 0; i < N; i++)
        cin >> people[i];
    // 인접 정보
    for (int i = 0; i < N; i++)
    {
        int v;
        cin >> v;
        while (v--)
        {
            int edge;
            cin >> edge;
            graph[i].push_back(edge - 1);
        }
    }

    answer = INF;
    int team[MAX];
    setTeam(0, team);

    if (answer == INF)
    {
        answer = -1;
    }

    cout << answer << '\n';
}