// 피보나치 수 2 (Top-Down)
// https://www.acmicpc.net/problem/2748
#include <iostream>
using namespace std;
const int MAX = 90 + 1;
long long N, cache[MAX];
long long fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    long long &ret = cache[n];
    if (ret != -1)
        return ret;
    return ret = fibo(n - 1) + fibo(n - 2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    fill_n(cache, MAX, -1);
    cout << fibo(N);
    return 0;
}