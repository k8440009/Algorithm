// DFS와 BFS
// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, V;
const int MAX = 1000 + 1;
vector<int> graph[MAX], picked;
bool visited[MAX];
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    picked.push_back(start);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
                picked.push_back(next);
            }
        }
    }
}
void dfs(int current)
{
    visited[current] = true;
    picked.push_back(current);
    for (int i = 0; i < graph[current].size(); i++)
    {
        int next = graph[current][i];
        if (!visited[next])
            dfs(next);
    }
}
void init()
{
    cin >> N >> M >> V;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // 정점번호가 작은 것 순으로 정렬
    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    dfs(V);
    vector<int>::iterator iter;
    for (iter = picked.begin(); iter != picked.end(); iter++)
        cout << *iter << ' ';
    picked.clear();
    cout << '\n';
    fill_n(visited, MAX, 0);
    bfs(V);
    for (iter = picked.begin(); iter != picked.end(); iter++)
        cout << *iter << ' ';
    return 0;
}