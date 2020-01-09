// 캔디 분배
// https://www.acmicpc.net/problem/3955
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
int N;
// 최대 공약수, x,y를 리턴
tuple<long long, long long, long long> extendedEuclidean(long long a, long long b)
{

    long long r0 = a, r1 = b;
    long long s0 = 1, s1 = 0;
    long long t0 = 0, t1 = 1;
    long long temp = 0, q = 0;

    while (r1)
    {
        q = r0 / r1;
        temp = r0;
        r0 = r1;
        r1 = temp - r1 * q;
        temp = s0;
        s0 = s1;
        s1 = temp - s1 * q;
        temp = t0;
        t0 = t1;
        t1 = temp - t1 * q;
    }
    // 최대 공약수. x,y
    return make_tuple(r0, s0, t0);
}
long long ceil(long long a, long long b)
{
    if (a >= 0)
    {
        return (a + b - 1) / b;
    }
    return a / b;
}
void solve(long long k, long long c)
{
    long long g, x0, y0;
    tie(g, x0, y0) = extendedEuclidean(k, c);
    if (g != 1)
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    long long t = min(ceil(-x0, c), ceil(y0, k)) - 1;
    if (y0 - 1e9 > k * t)
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    cout << y0 - t * k << '\n';
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // extendedEuclidean(9, 5);

    cin >> N;
    while (N--)
    {
        long long k, c;
        cin >> k >> c;
        solve(k, c);
    }
}

/*
	참고
	https://baeharam.github.io/posts/algorithm/extended-euclidean/
	https://casterian.net/archives/601
*/