// 택시 기하학
// https://www.acmicpc.net/problem/3053
#include <bits/stdc++.h>

using namespace std;
/*
    (0,0) (x1, y1) -> 마름모
*/
#define PI 3.1415926535897
int main()
{
    double r;
    cin >> r;
    cout << fixed;
    cout.precision(6);
    cout << (double)(r * r * PI) << '\n';
    cout << (double)(r * r * 2) << '\n';
    return 0;
}