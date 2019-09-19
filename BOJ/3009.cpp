// 네 번째 점
// https://www.acmicpc.net/problem/3009
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<int, int> x;
    map<int, int> y;

    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
    }

    for (auto iter1 : x)
    {
        if (iter1.second == 1)
            cout << iter1.first << ' ';
    }

    for (auto iter2 : y)
    {
        if (iter2.second == 1)
            cout << iter2.first << '\n';
    }

    return 0;
}