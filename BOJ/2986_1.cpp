// 파스칼
// https://www.acmicpc.net/problem/2986
#include <iostream>
using namespace std;
typedef long long ll;
ll N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    ll cnt = 1;
    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            cnt = N / i;
            break;
        }
    }

    cout << N - cnt << '\n';

    return 0;
}

/*
    참고
    https://bitwise.tistory.com/217
    https://twinparadox.tistory.com/433
*/