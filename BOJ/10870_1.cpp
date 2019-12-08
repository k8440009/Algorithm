// 피보나치 수 5
// https://www.acmicpc.net/problem/10870
#include <iostream>
using namespace std;
int N;
int fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cout << fibo(N);

    return 0;
}