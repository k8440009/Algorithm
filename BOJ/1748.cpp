// 수 이어 쓰기
// https://www.acmicpc.net/problem/1748
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    long long answer = 0;
    // 1 ~ 9 => (9-1 + 1) * 1;
    // 10 ~99 => (99 - 10 + 1) * 2;
    // 100 ~ 120 => (120 - 100 + 1) * 3;
    for (int start = 1, len = 1; start <= N; start *= 10, len++)
    {
        int end = start * 10 - 1;
        if (end > N)
        {
            end = N;
        }
        answer += (long long)(end - start + 1) * len;
    }
    cout << answer << '\n';
    return 0;
}