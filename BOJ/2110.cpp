// 공유기 설치
// https://www.acmicpc.net/problem/2110
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int N, C;
int home[MAX];
bool check(int dist)
{
    int cnt = 1;
    int prev = home[0];

    for (int i = 1; i < N; i++)
    {
        if (home[i] - prev >= dist)
        {
            cnt++;
            prev = home[i];
        }
    }

    // 조건 충족
    if (cnt >= C)
        return true;
    return false;
}
int main()
{
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> home[i];

    sort(home, home + N);

    // 최소 거리, 최대거리
    int low = 1;
    int high = home[N - 1] - home[0];
    int result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
        {
            result = max(result, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << result << '\n';
    return 0;
}