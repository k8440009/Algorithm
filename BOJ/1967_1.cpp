// 트리의 지름
// https://www.acmicpc.net/problem/1967
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10000 + 1;
struct NODE
{
    int v, w;
};
int N, V, U, R;
vector<NODE> adj[MAX];
int dist[MAX];

void dfs(int v, int d)
{
    dist[v] = d;

    if (dist[v] > R)
    {
        R = dist[v];
        U = v;
    }

    for (NODE node : adj[v])
    {
        int next = node.v;
        int weight = node.w;

        if (dist[next] == 0)
        {
            dfs(next, d + weight);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        NODE node;
        int parent, child, weight;
        cin >> parent >> child >> weight;

        node.v = child, node.w = weight;
        adj[parent].push_back(node);
        node.v = parent, node.w = weight;
        adj[child].push_back(node);
    }
    // 가장 멀리있는 끝점 구하기
    dfs(1, 0);

    R = 0;
    fill_n(dist, MAX, 0);

    // 끝점을 기준으로 가장 멀리있는 점 구하기
    dfs(U, 0);
    cout << R << '\n';
}
/*
    참고
    https://mygumi.tistory.com/226
    https://lmcoa15.tistory.com/56
    https://jaimemin.tistory.com/531
*/