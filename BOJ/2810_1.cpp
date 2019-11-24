// 컵홀더
// https://www.acmicpc.net/problem/2810
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
string seat;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> seat;

    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
        // 마즈막 자리
        if (i == N - 1)
        {
            cnt++;
            break;
        }
        // 커플석 체크
        if (seat[i] != seat[i + 1])
            cnt++;
        else if (seat[i] == seat[i + 1])
        {
            if (seat[i] == 'L')
            {
                cnt++;
                i += 1;
                continue;
            }
            else
                cnt++;
        }
    }

    cout << min(N, cnt) << '\n';

    return 0;
}
/*
    참고
    https://jaimemin.tistory.com/930
*/