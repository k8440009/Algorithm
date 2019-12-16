// 분해합
// https://www.acmicpc.net/problem/2231
#include <iostream>
using namespace std;
int N;
int recursive(int num, int total)
{
    if (num == 0)
        return total;
    else
        return recursive(num / 10, total + (num % 10));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int newNum = i + recursive(i, 0);
        if (N == newNum)
        {
            cout << i;
            return 0;
        }
    }

    cout << 0; // 생성자가 없는 경우
    return 0;
}