// 1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱
#include <iostream>
using namespace std;
int recursion(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * recursion(a, b - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc, a, b;
    while (true)
    {
        cin >> tc >> a >> b;
        cout << "#" << tc << ' ' << recursion(a, b) << '\n';
        if (tc == 10)
            break;
    }

    return 0;
}