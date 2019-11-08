// 가장 먼 노드
// https://programmers.co.kr/learn/courses/30/lessons/49189
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MAX = 20000 + 1;
vector<int> graph[MAX];
vector<vector<int>> answer(MAX);
bool visited[MAX];
int maxDepth = 0;
void bfs(int node)
{
    // 가장 멀리 떨어진 노드를 찾는다.
    queue<pair<int, int>> q;
    q.push(make_pair(node, 0));
    visited[node] = true;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int now = cur.first;    // 현재 노드
        int depth = cur.second; // 현재 깊이
        q.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (!visited[next])
            {
                maxDepth = max(maxDepth, depth + 1);
                q.push(make_pair(next, depth + 1));
                visited[next] = true;
                answer[depth + 1].push_back(next);
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge)
{
    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0], b = edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    return answer[maxDepth].size();
}