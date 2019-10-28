// 인공지능 시계
// https://www.acmicpc.net/problem/2530
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int hour, minute, second;
    cin >> hour >> minute >> second;
    int needTime;
    cin >> needTime;

    second += needTime;
    minute += second / 60;
    second %= 60;

    hour += minute / 60;
    minute %= 60;

    hour %= 24;

    cout << hour << ' ' << minute << ' ' << second << ' ';
    return 0;
}