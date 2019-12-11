// 369
// https://www.acmicpc.net/problem/17614
#include <iostream>
using namespace std;
int N;
int recursive(int num, int cnt)
{
    // 10의 자리 이상
    if (num >= 10)
    {
        int a = num / 10;
        if (a == 3 || a == 6 || a == 9)
            return recursive(num % 10, cnt + 1);
        else
            return recursive(num % 10, cnt);
    }
    else
    {
        if (num == 3 || num == 6 || num == 9)
            return cnt + 1;
        else
            return cnt;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    long long result = 0;
    for (int i = 1; i <= N; i++)
        result += recursive(i, 0);
    cout << result << '\n';

    return 0;
}