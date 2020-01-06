// 동전 0
// https://www.acmicpc.net/problem/11047
#include <iostream>
using namespace std;
/*
    코인들이 서로 배수이기 때문에 그리디 사용가능
*/
int N, K, coin[10];
int solve()
{
    int total = K, cnt = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (total == 0)
            break;
        if (total >= coin[i])
        {
            cnt += (total / coin[i]);
            total %= coin[i];
        }
    }
    return cnt;
}
void init()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> coin[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << solve();
    return 0;
}