// A + B - 7
// https://www.acmicpc.net/problem/11021
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;
    for (int tc = 1; tc <= testCase; tc++)
    {
        int a, b;
        cin >> a >> b;

        cout << "Case #" << tc << ": " << a + b << '\n';
    }
    return 0;
}