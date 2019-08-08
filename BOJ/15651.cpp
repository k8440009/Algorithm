// N과 M (3)
// https://www.acmicpc.net/problem/15651
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int N, M;
void recursive(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        a.push_back(i);
        recursive(cnt + 1);
        a.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    recursive(0);

    return 0;
}