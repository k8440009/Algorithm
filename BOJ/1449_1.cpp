// 수리공 항승
// https://www.acmicpc.net/problem/1449
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000 + 1;
int N, L;
bool tape[MAX];
vector<int> location;
int solve()
{
    // 길이가 L인 테이프 붙이기
    for (int i = 0; i < N; i++)
    {
        int pos = location[i];
        // 물이 새는 곳에 테이프를 붙인다.
        if (!tape[pos])
        {
            for (; pos < location[i] + L; pos++)
            {
                if (pos < MAX)        // 인덱스 주의
                    tape[pos] = true; // 테이프 위치 체크
                else
                    break;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= MAX; i++)
    {
        // 1~1000까지 위치를 탐색하면서 테이프 갯수를 체크한다.
        if (tape[i])
        {
            cnt++;
            i += (L - 1); // L-1 만큼 이동
        }
    }
    return cnt;
}
void init()
{
    cin >> N >> L;
    location.resize(N);
    for (int i = 0; i < N; i++)
        cin >> location[i];
    sort(location.begin(), location.end());
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << solve();
    return 0;
}