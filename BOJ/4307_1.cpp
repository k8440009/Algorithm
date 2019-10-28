// 개미
// https://www.acmicpc.net/problem/4307
// 그리디
#include <iostream>
#include <algorithm>
using namespace std;
int L, N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> L >> N; // 막대 길이, 개미 수
        int minTime = 0, maxTime = 0;
        for (int i = 0; i < N; i++)
        {
            int ant;
            cin >> ant;
            // 왼쪽으로 가는 경우, 오른쪽으로 가는 경우 중 최소
            int antMax = max(ant, L - ant);
            // 왼쪽으로 가는 경우, 오른쪽으로 가는 경우 중 최대
            int antMin = min(ant, L - ant);

            minTime = max(minTime, antMin);
            maxTime = max(maxTime, antMax);
        }
        cout << minTime << ' ' << maxTime << '\n';
    }

    return 0;
}

/*
    참고
    https://jaimemin.tistory.com/1178
*/