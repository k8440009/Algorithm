// 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095
#include <bits/stdc++.h>
using namespace std;
// bf
int cnt = 0;
void recursive(int now, int number)
{
    // 기저 사례
    if (now >= number)
    {
        if (now == number)
            cnt++;
        return;
    }

    // 1을 더할 때
    recursive(now + 1, number);
    // 2를 더 할 때
    recursive(now + 2, number);
    // 3을 더 할 때
    recursive(now + 3, number);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cnt = 0;
        recursive(0, n);
        cout << cnt << '\n';
    }

    return 0;
}