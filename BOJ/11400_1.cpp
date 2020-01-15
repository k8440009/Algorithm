// 단절선
// https://www.acmicpc.net/problem/11400
/*
	시간복잡도 : O(V + E)
	DFS 스패닝 트리를 이용하여 A번째 정점에서 부모로 가는 간선을 제외하고
	나머지 간선에서 아직 방문 안한 노드에서 얻어온 discover 번호가 나의 discover번호보다 클 경우
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 100000 + 1;
int V, E, root, cnt, discover[MAX];
vector<int> adj[MAX];
set<pair<int, int>> cut;
int dfs(int curr, int prev)
{
    discover[curr] = ++cnt;
    int result = discover[curr];
    for (int next : adj[curr])
    {
        if (next == prev)
            continue;
        if (discover[next] != 0)
            result = min(result, discover[next]);
        else
        {
            int temp = dfs(next, curr);
            result = min(result, temp);
            if (temp > discover[curr])
            {
                if (curr < next)
                    cut.insert(make_pair(curr, next));
                else
                    cut.insert(make_pair(next, curr));
            }
        }
    }
    return result;
}
void solve()
{
    dfs(1, 0);
    // 단절선 개수 출력
    cout << cut.size() << '\n';
    // 단절선 출력
    for (const pair<int, int> &p : cut)
        cout << p.first << ' ' << p.second << '\n';
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