// 반올림
// https://www.acmicpc.net/problem/2033
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, t = 1;
    cin >> n;
    while (n > t * 10)
    {
        n += 5 * t;   // 반올림
        t *= 10;      // 10 증가
        n -= (n % t); // 나머지 제거
    }

    cout << n << '\n';

    return 0;
}

/*
    참고
    https://bitwise.tistory.com/206
*/