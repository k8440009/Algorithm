// 수들의 합
// https://www.acmicpc.net/problem/1789
#include <iostream>
using namespace std;
typedef long long ll;
ll N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N; // 합계

    int num = 1;
    ll total = 0;
    while (1)
    {
        total += num;
        if (total > N)
        {
            num--;
            break;
        }
        num++;
    }

    cout << num << '\n';
    return 0;
}