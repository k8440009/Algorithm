// 캠핑
// https://www.acmicpc.net/problem/4796
#include <iostream>
using namespace std;
int L, P, V;
int greedy()
{
    int days = 0;
    days += (V / P) * L;
    int reminder = V % P;
    if (reminder >= L)
        days += L;
    else
        days += reminder;
    return days;
}
bool init()
{
    cin >> L >> P >> V;
    if (L == 0 && P == 0 && V == 0)
        return false;
    return true;
}
int main()
{
    int tc = 1;
    while (init())
    {
        cout << "Case " << tc << ": " << greedy() << '\n';
        tc++;
    }

    return 0;
}