// 직사각형을 만드는 방법
// https://www.acmicpc.net/problem/8320
#include <iostream>
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = i; i * j <= N; j++)
            cnt++;

    cout << cnt << '\n';
}