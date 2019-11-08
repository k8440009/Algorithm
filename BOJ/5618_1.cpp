// 공약수
// https://www.acmicpc.net/problem/5618
#include <iostream>
#include <algorithm>
using namespace std;
// 최대공약수의 약수들이 공약수의 집합
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c = 0, g = 0;

    cin >> n;
    if (n == 2)
    {
        cin >> a >> b;
        g = gcd(a, b);
    }
    else
    {
        cin >> a >> b >> c;
        g = gcd(a, gcd(b, c));
    }

    for (int i = 1; i <= g; i++)
        if (g % i == 0)
            cout << i << '\n';

    return 0;
}