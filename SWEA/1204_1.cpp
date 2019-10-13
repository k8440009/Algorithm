// 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    for (int a = 1; a <= 10; a++)
    {
        int ts;
        cin >> ts;
        map<int, int> m;
        for (int i = 0; i < 1000; i++)
        {
            int num;
            cin >> num;
            m[num] += 1;
        }

        map<int, int>::iterator iter;
        int maxNum = 0;
        int maxR = 0;

        for (iter = m.begin(); iter != m.end(); iter++)
        {
            if (iter->second > maxR)
            {
                maxNum = iter->first;
                maxR = iter->second;
            }
            else if (iter->second == maxR)
                maxNum = max(maxNum, iter->first);
        }

        cout << "#" << a << ' ' << maxNum << '\n';
    }

    return 0;
}