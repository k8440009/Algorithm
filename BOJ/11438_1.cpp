// LCA 2
// https: //www.acmicpc.net/problem/11438
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
    - 시간 복잡도 -
    O(N*logM)
    - 설명 - 
    LCA로 푸는게 맞지만 범위가 작아서 간단하게 dfs를 사용해도 된다
*/
const int MAX = 100000 + 1;
const int K = 18;
int depth[MAX], parent[MAX][K];
vector<int> adj[MAX];
int N, M;
void solve()
{
    cin >> M;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        if (depth[u] < depth[v])
            swap(u, v);
        int diff = depth[u] - depth[v];
        // 깊이 차 (diff)를 없애며 u를 이동시킴
        for (int j = 0; diff; j++)
        {
            if (diff % 2)
                u = parent[u][j];
            diff /= 2;
        }
        // u와 v가 다르면 동시에 일정 높이만큼 위로 이동시킴
        if (u != v)
        {
            for (int j = K - 1; j >= 0; j--)
            {
                if (parent[u][j] != -1 && parent[u][j] != parent[v][j])
                {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            // 마지막엔 두 정점 u,v의 부모가 같으므로 한번 더 올림
            u = parent[u][0];
        }

        cout << u << '\n';
    }
}
// DFS를 사용하여 트리 제작, depth 배열 채움
void makeTreeByDfs(int curr)
{
    for (int next : adj[curr])
    {
        if (depth[next] == -1)
        {
            parent[next][0] = curr;        // 부모
            depth[next] = depth[curr] + 1; // 깊이
            makeTreeByDfs(next);
        }
    }
}
void init()
{
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_n(depth, MAX, -1), fill_n(parent[0], MAX * K, -1);
    depth[1] = 0;
    makeTreeByDfs(1);
    // parent 배열을 채운다.
    for (int j = 0; j < K - 1; j++)
    {
        for (int i = 1; i <= N; i++)
            if (parent[i][j] != -1)
                parent[i][j + 1] = parent[parent[i][j]][j];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}

/*
    참조
    https://kks227.blog.me/
    https://www.acmicpc.net/problem/11438
*/