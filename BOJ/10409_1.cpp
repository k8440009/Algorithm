// 서버
// https://www.acmicpc.net/problem/10409
#include <iostream>
using namespace std;
int N, T;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
    int total = 0, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        total += num;

        if (total <= T)
            cnt++;
    }

    cout << cnt;
    return 0;
}