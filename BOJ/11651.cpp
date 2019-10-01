// 좌표 정렬하기 2
// https://www.acmicpc.net/problem/11651
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}