// 심부름 가는 길
// https://www.acmicpc.net/problem/5554
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d, total = 0;
    cin >> a >> b >> c >> d;
    total += (a + b + c + d);
    cout << total / 60 << '\n';
    cout << total % 60;
    return 0;
}
