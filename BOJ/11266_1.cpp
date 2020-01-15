// 단절점
// https://www.acmicpc.net/problem/11266
/* 
    단절점
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 10000 + 1;
int V, E, root, cnt, discover[MAX];
vector<int> adj[MAX];
set<int> cut;
int dfs(int curr)
{
    discover[curr] = ++cnt;
    int result = discover[curr], child = 0;
    for (int next : adj[curr])
    {
        //이미 dfs에서 탐색된 정점이라면
        // 현재 정점 방문순서와 탐색된 정점의 방문순서중 min값을 갖는다.
        if (discover[next] != 0)
            result = min(result, discover[next]);
        else
        {
            int temp = dfs(next);
            result = min(result, temp);
            // A번 정점에서 자식 노드들이 정점 A를 거치지 않고
            // 장점 A보다 빠른 방문 번호를 가진 정점으로 갈 수 없다면 단절점이다.
            if (curr != root && temp >= discover[curr])
                cut.insert(curr);
            child++;
        }
    }
    // 루트이고 자식이 2 이상인 경우 단절점
    if (curr == root && child > 1)
        cut.insert(curr);
    return result;
}
void solve()
{
    // dfs 탐색
    for (int i = 1; i <= V; i++)
        if (!discover[i])
        {
            root = i; // 처음 시작하는 번호가 루트
            dfs(i);
        }
    // 단절점 개수, 단절점의 번호
    cout << cut.size() << '\n';
    for (int n : cut)
        cout << n << ' ';
    cout << '\n';
}
void init()
{
    cin >> V >> E;
    int a, b;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
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
	https://www.crocus.co.kr/1164
*/