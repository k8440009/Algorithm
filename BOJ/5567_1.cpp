// 결혼식
// https://www.acmicpc.net/problem/5567
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 500 + 1;
int N, M;
vector<int> graph[MAX];
bool visited[MAX];
void dfs(int cur, int depth)
{
    if (depth == 3)
        return;

    visited[cur] = true;

    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        dfs(next, depth + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    int cnt = 0;
    for (int i = 2; i <= N; i++)
        if (visited[i])
            cnt++;

    cout << cnt << '\n';

    return 0;
}

/*
    참고
    https://velog.io/@skyepodium/Baekjoon-5567-%EA%B2%B0%ED%98%BC%EC%8B%9D-qojrsssji0
    https://mygumi.tistory.com/147
    https://jaimemin.tistory.com/597
*/