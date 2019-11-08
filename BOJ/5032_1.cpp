// 탄산 음료
// https://www.acmicpc.net/problem/5032
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int e, f, c;
    cin >> e >> f >> c;

    int cnt = 0;       // 먹은 탄산 음료
    int drink = 0;     // 콜라 갯수
    int blank = e + f; // 빈병
    while (blank >= c)
    {
        drink = blank / c;
        blank %= c;
        cnt += drink;
        blank += (drink);
    }

    cout << cnt << '\n';
}