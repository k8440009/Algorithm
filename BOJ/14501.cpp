// 퇴사
// https://www.acmicpc.net/problem/14501
#include <bits/stdc++.h>
using namespace std;
int N;
const int MAX = 15;
int T[MAX + 1];
int P[MAX + 1];
int answer = 0;
void rec(int day, int sum)
{
    if (day == N + 1)
    {
        answer = max(answer, sum);
        return;
    }

    if (day > N + 1)
        return;

    rec(day + T[day], sum + P[day]);
    rec(day + 1, sum);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];

    rec(1, 0);

    cout << answer << '\n';

    return 0;
}