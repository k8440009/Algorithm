// 배수와 약수
// https://www.acmicpc.net/problem/5086
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        string answer;
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        if (a < b)
        {
            if (b % a == 0)
                answer = "factor";
            else
            {
                answer = "neither";
            }
        }
        else if (a > b)
        {
            if (a % b == 0)
                answer = "multiple";
            else
            {
                answer = "neither";
            }
        }

        cout << answer << '\n';
    }

    return 0;
}