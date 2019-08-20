// 시험 감독
// https://www.acmicpc.net/problem/13458
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    int m, s;
    cin >> m >> s;

    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        // 1. 메인 감독관 만큼 값을 뺀다.
        long long total = 1;
        a[i] -= m;
        // 2. 부 감독관을 사용할것인지 아닌지 결정
        if (a[i] > 0)
        {
            int cnt = 0;
            // 부 감독관이 클떼
            if (s > a[i])
            {
                total += cnt + 1;
            }
            // 응시자 수가 더 많을 때
            else
            {
                if (a[i] % s == 0)
                    total += (a[i] / s);
                else
                    total += (a[i] / s) + 1;
            }
        }
        answer += total;
    }

    cout << answer << '\n';
    return 0;
}