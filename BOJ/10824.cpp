// 네 수
// https://www.acmicpc.net/problem/10824
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    long long tmp1 = stoll(a + b);
    long long tmp2 = stoll(c + d);

    cout << tmp1 + tmp2 << '\n';

    return 0;
}