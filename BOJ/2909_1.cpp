// 캔디 구매
// https://www.acmicpc.net/problem/2909
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll C, K, N = 1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C >> K;
    // pow가 double이라 막 쓰면 틀린다.
    for (int i = 0; i < K; i++)
        N *= 10;
    int a = (C / N) * N;
    if (C % N >= N / 2)
        cout << a + N;
    else
        cout << a;
    return 0;
}