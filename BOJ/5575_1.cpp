// 타임 카드
// https://www.acmicpc.net/problem/5575
#include <iostream>
using namespace std;
void calculate(int sh, int sm, int ss, int eh, int em, int es)
{
    int hour = eh - sh;
    int minute = em - sm;
    if (minute < 0)
    {
        minute += 60;
        hour -= 1;
    }
    int second = es - ss;
    if (second < 0)
    {
        second += 60;
        minute -= 1;
        if (minute < 0)
        {
            minute += 60;
            hour -= 1;
        }
    }

    cout << hour << ' ' << minute << ' ' << second << '\n';

    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sh, sm, ss, eh, em, es;
    for (int i = 0; i < 3; i++)
    {
        cin >> sh >> sm >> ss >> eh >> em >> es;
        calculate(sh, sm, ss, eh, em, es);
    }

    return 0;
}