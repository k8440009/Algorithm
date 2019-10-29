// 거스름돈
// https://www.acmicpc.net/problem/5585
#include <iostream>
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int exchange[6] = {500, 100, 50, 10, 5, 1};
    // 거스름돈 가장 작게
    cin >> N;
    N = 1000 - N;
    int cnt = 0;
    int index = 0;
    // 동전 교환이 끝날 떄까지 반복
    while (true)
    {
        if (index == 7)
            break;

        if (N >= exchange[index])
        {
            int temp = N / exchange[index];
            cnt += temp;
            N -= (exchange[index] * temp);
        }

        index += 1;
    }

    cout << cnt << '\n';
}