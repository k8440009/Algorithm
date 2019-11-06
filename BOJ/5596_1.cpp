// 시험 점수
// https://www.acmicpc.net/problem/5596
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s = 0, t = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    s = (a + b + c + d);
    cin >> a >> b >> c >> d;
    t = (a + b + c + d);
    cout << max(s, t) << '\n';
}