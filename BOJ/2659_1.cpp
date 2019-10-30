// 십자카드 문제
// https://www.acmicpc.net/problem/2659
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int num[4];
int makeCycle()
{
    int cycleNum = 987654321;

    for (int i = 0; i < 4; i++)
    {
        int temp = 0;
        for (int j = 0; j < 4; j++)
        {
            temp += (num[(i + j) % 4] * pow(10, 3 - j));
        }

        cycleNum = min(cycleNum, temp);
    }

    return cycleNum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++)
        cin >> num[i];

    // 주어진 값의 시계수 생성
    int cycleNum = makeCycle();

    int cnt = 0;
    for (int i = 1111; i <= cycleNum; i++)
    {
        int temp = i;
        num[0] = temp / 1000;
        temp %= 1000;
        num[1] = temp / 100;
        temp %= 100;
        num[2] = temp / 10;
        temp %= 10;
        num[3] = temp / 1;

        // 사이클 수 생성
        temp = makeCycle();
        // 본래 수와 사이클 수가 같으면 시계수
        if (temp == i)
            cnt += 1;
    }

    cout << cnt + 1 << '\n';
}