// 소인수분해
// https://www.acmicpc.net/problem/11653
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;

    for (int i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            cout << i << '\n';
            num /= i;
        }
    }

    if (num > 1)
        cout << num << '\n';

    return 0;
}