// 나머지
// https://www.acmicpc.net/problem/3052
#include <bits/stdc++.h>
using namespace std;
int mod[42];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
        mod[a[i] % 42] += 1;
    }

    int cnt = 0;
    for (int i = 0; i < 42; i++)
    {
        if (mod[i] > 0)
            cnt += 1;
    }

    cout << cnt << '\n';
    return 0;
}