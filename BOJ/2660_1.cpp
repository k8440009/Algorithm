// 회장뽑기
// https: //www.acmicpc.net/problem/2660
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
int N;
vector<int> graph[MAX];
bool visited[MAX];
vector<int> answer;
vector<pair<int, int>> temp;
int score = 987654321;

void bfs(int node)
{
    queue<pair<int, int>> q;
    visited[node] = true;
    // 다음 노드와 점수 삽입
    q.push(make_pair(node, 0));

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // int next = graph[node]
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (!visited[graph[cur][i]])
            {
                int next = graph[cur][i];
                visited[next] = true;
                q.push(make_pair(next, cnt + 1));
            }
        }

        if (q.empty())
        {
            score = min(score, cnt);
            temp.push_back(make_pair(node, cnt));
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        // 모든 노드 거리 탐색
        bfs(i);
        fill_n(visited, MAX, 0);
    }

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].second == score)
            answer.push_back(temp[i].first);
    }

    sort(answer.begin(), answer.end());
    // 점수와 후보수
    cout << score << ' ' << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';

    return 0;
}
