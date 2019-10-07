// 게리맨더링
// https://www.acmicpc.net/problem/17471
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10;
const int INF = 987654321;
int N, answer;
vector<int> people;
vector<vector<int>> graph;
bool bfs(int teamNum, int team[])
{
    bool visited[MAX];
    fill_n(visited, MAX, 0);

    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        if (teamNum == team[i])
        {
            q.push(i);
            visited[i] = true;
            break;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < N; i++)
        {
            // 방문했거나 우리 팀이 아닌 경우 pass
            if (visited[i] || teamNum != team[i])
                continue;
            // 우리팀인 경우 연결된 경로에서 다른 우리팀 노드를 찾는다.
            for (int j = 0; j < graph[cur].size(); j++)
            {
                if (i == graph[cur][j])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (teamNum != team[i])
            continue;
        if (!visited[i])
            return false;
    }

    return true;
}
// 재귀로 팀 정하기
void setTeam(int index, int team[])
{
    if (index == N)
    {
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
        }

        return;
    }

    team[index] = 1; // 1번 팀
    setTeam(index + 1, team);
    team[index] = 0; // 0번 팀
    setTeam(index + 1, team);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    people.resize(N);
    graph.resize(N);

    for (int i = 0; i < N; i++)
        cin >> people[i];

    for (int i = 0; i < N; i++)
    {
        int v;
        cin >> v;
        while (v--)
        {
            int node;
            cin >> node;
            graph[i].push_back(node - 1);
        }
    }

    answer = INF;
    int team[MAX];
    setTeam(0, team);
    if (answer == INF)
        answer = -1;

    cout << answer << '\n';

    return 0;
}