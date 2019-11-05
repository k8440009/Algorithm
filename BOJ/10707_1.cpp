// 수도요금
// https://www.acmicpc.net/problem/10707
#include <iostream>
#include <algorithm>
using namespace std;
int X, Y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int basicX, basicY, limitY, addY, water, answer = 0;
    // X, Y 최소값 구함
    cin >> basicX >> basicY >> limitY >> addY >> water;

    // X의 수도 요금
    int fareX = water * basicX;
    // Y의 수도 요금
    int fareY = basicY;
    // 상항 보다 큰 경우
    if (water > limitY)
    {
        // 추가
        int a = water - limitY;
        fareY += (addY * a);
    }

    answer = min(fareX, fareY);

    cout << answer << '\n';

    return 0;
}