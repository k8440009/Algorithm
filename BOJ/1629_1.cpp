// 곱셈
// https://www.acmicpc.net/problem/1629
#include <iostream>
using namespace std;
int A, B, C;
long long multiply(int a, int b, int c)
{
    if (b == 1)
        return a;
    if (b % 2 == 0)
    {
        long long half = multiply(a, b / 2, c) % c;
        return half * half % c;
    }
    else
        return multiply(a, b - 1, c) * a % c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C;

    long long num = multiply(A, B, C) % C;

    cout << num << '\n';
}