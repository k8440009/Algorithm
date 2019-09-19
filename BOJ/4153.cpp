//  직각삼각형
// https://www.acmicpc.net/problem/4153
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }

    return 0;
}