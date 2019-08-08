// N M (1)
#include <bits/stdc++.h>
using namespace std;
/*
    참고

    조합 구현하기
    https://yabmoons.tistory.com/99

    순열 구현하기
    https://yabmoons.tistory.com/100
    
 */
#define MAX 9
int n, m;

vector<int> a;
bool visited[MAX];
// dfs(인덱스)
void dfs(int index)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';

        return;
    }
    for (int i = 1; i <= n; i++)
    {
        // 방문했으면 pass
        if (visited[i])
            continue;
        visited[i] = true;
        a.push_back(i);
        dfs(index + 1);
        visited[i] = false;
        a.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    dfs(0);

    return 0;
}