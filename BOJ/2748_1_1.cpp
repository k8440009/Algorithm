// 피보나치 수 2 (Bottom-Up)
// https://www.acmicpc.net/problem/2748
#include <iostream>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
ll d[91];
int main(void)
{
    int n;
    cin >> n;

    d[1] = 0;
    d[2] = 1;
    rep(i, 3, 91)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    cout << d[n] << '\n';

    return 0;
}