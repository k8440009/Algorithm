// 회의실배정
// https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int>> schedule;
int solve()
{
    int cnt = 1;
    int start = schedule[0].second, end = schedule[0].first;
    for (int i = 1; i < N; i++)
    {
        int nStart = schedule[i].second, nEnd = schedule[i].first;
        if (nStart < end)
            continue;
        else
        {
            start = nStart;
            end = nEnd;
            cnt++;
        }
    }
    return cnt;
}
void init()
{
    cin >> N;
    schedule.resize(N);
    int start, end;
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        schedule[i].first = end, schedule[i].second = start;
    }
    sort(schedule.begin(), schedule.end());
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