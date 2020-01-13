// LCA
// https: //www.acmicpc.net/problem/11437
#include <iostream>
#include <vector>
using namespace std;
/*
    - 시간 복잡도 -
    O(N*M)
    - 설명 - 
    LCA로 푸는게 맞지만 범위가 작아서 간단하게 dfs를 사용해도 된다
*/
const int MAX = 50000 + 1;
int depth[MAX], parent[MAX];
vector<int> adj[MAX];
int N, M;
void solve()
{
    cin >> M;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        if (depth[a] < depth[b])
            swap(a, b);
        //  a의 깊이가 b의 깊이 보다 큰 경우 같은 노드에서 마주 칠 때 까지 올려준다.
        while (depth[a] != depth[b])
            a = parent[a];
        // u,v 노드 중에서 더 큰 노드의 깊이를 끌어 올려준 다음에
        // 두 노드에서 동시에 하나씩 올라가며 같은 노드에서 마주 칠 때 까지 올려준다.
        while (a != b)
            a = parent[a], b = parent[b];
        cout << a << '\n';
    }
}
// DFS를 사용하여 깊이 계산
void makeTreeByDfs(int curr)
{
    for (int next : adj[curr])
    {
        if (depth[next] == -1)
        {
            parent[next] = curr;           // 부모
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
    fill_n(depth, MAX, -1), fill_n(parent, MAX, -1);
    depth[1] = 0;
    makeTreeByDfs(1);
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