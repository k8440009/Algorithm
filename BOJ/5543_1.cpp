// 상근 날드
// https://www.acmicpc.net/problem/5543
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int minBuger = 987654321;
    int minDrink = 987654321;
    for (int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        if (i < 3)
            minBuger = min(minBuger, temp);
        else
            minDrink = min(minDrink, temp);
    }

    cout << minBuger + minDrink - 50 << '\n';
    return 0;
}