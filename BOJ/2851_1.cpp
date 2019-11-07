// 슈퍼 마리오
// https://www.acmicpc.net/problem/2851
#include <iostream>
using namespace std;
int num[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int now = 0, prev = 0;
    for (int i = 0; i < 10; i++)
        cin >> num[i];
    for (int i = 0; i < 10; i++)
    {
        prev = now;
        now += num[i];

        // 클 때
        if (now > 100)
        {
            // 차이
            int a = now - 100;
            int b = 100 - prev;

            if (a > b)
            {
                cout << prev << '\n';
                return 0;
            }
            else if (a < b)
            {
                cout << now << '\n';
                return 0;
            }
            else
            {
                cout << now << '\n';
                return 0;
            }
        }
        // 같을 때
        else if (now == 100)
        {
            cout << now << '\n';
            return 0;
        }
    }

    cout << now << '\n';
    return 0;
}