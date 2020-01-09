// 분수 합
//https://www.acmicpc.net/problem/1735
#include <iostream>
using namespace std;
// gcd(a,b) = gcd(b, a%b)
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return abs(a);
}
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // cout << gcd(a, c) << ' ' << gcd(b, d);
    int ch = a * d + b * c;
    int pa = b * d;
    int temp = 0;
    if (ch > pa)
        temp = gcd(ch, pa);
    else
        temp = gcd(pa, ch);

    cout << ch / temp << ' ' << pa / temp << '\n';
    return 0;
}
