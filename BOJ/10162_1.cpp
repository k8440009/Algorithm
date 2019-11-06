// 전자레인지
// https://www.acmicpc.net/problem/10162
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int time, a = 0, b = 0, c = 0;
    cin >> time;
    if (time % 10 != 0)
        cout << -1 << '\n';
    else
    {
        if (time >= 300)
        {
            a += (time / 300);
            time %= 300;
        }
        if (time >= 60)
        {
            b += (time / 60);
            time %= 60;
        }
        if (time >= 10)
        {
            c += (time / 10);
            time %= 10;
        }

        cout << a << ' ' << b << ' ' << c << ' ';
    }
}