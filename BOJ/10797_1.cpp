// 10부제
// https://www.acmicpc.net/problem/10797
#include <iostream>
using namespace std;
int N, answer;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N; // 자동차 1의 자리
    for (int i = 0; i < 5; i++)
    {
        int car;
        cin >> car;
        if (car == N)
            answer += 1;
    }

    cout << answer << '\n';
}