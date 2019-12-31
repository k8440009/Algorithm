// 연결 요소의 갯수
// https://www.acmicpc.net/problem/11724
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000 + 1;
int N, M;
vector<int> graph[MAX];
bool visited[MAX];
void dfs(int current)
{
    visited[current] = true;
    for (int i = 0; i < graph[current].size(); i++)
    {
        int next = graph[current][i];
        if (!visited[next])
            dfs(next);
    }
}
void init()
{
    cin >> N >> M;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            answer++;
        }
    }
    cout << answer;
    return 0;
}