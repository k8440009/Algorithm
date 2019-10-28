// 알람 시계
// https://www.acmicpc.net/problem/2884
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int hour, minute;
    cin >> hour >> minute;
    // 시간이 0이고, 분이 음수 인 경우
    if (hour == 0 && minute < 45)
    {
        hour = 23;
        minute += 15;
    }
    // 분이 45보다 큰 경우
    else if (minute >= 45)
        minute -= 45;
    else
    {
        hour -= 1;
        minute += 15;
    }

    cout << hour << ' ' << minute << '\n';
    return 0;
}