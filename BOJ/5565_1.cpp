// 영수증
// https://www.acmicpc.net/problem/5565
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int total;
    cin >> total;
    for (int i = 0; i < 9; i++)
    {
        int temp;
        cin >> temp;
        total -= temp;
    }

    cout << total << '\n';
}