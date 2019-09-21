// A + B - 8
// https://www.acmicpc.net/problem/11022
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Case #1: 1 + 1 = 2
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int a, b;
        cin >> a >> b;
        // Case #1: 1 + 1 = 2
        cout << "Case #" << tc << ": " << a << " + " << b << " = " << a + b << '\n';
    }
    return 0;
}