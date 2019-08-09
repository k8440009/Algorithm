// 부분수열의 합
// https://www.acmicpc.net/problem/1182
#include <bits/stdc++.h>
using namespace std;
int N, S;
int cnt = 0;
vector<int> a;
void rec(int index, int sum)
{
    if (index == N)
    {
        if (sum == S)
            cnt++;
        return;
    }

    rec(index + 1, sum + a[index]);
    rec(index + 1, sum);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    rec(0, 0);
    if (S == 0)
        cnt -= 1;
    cout << cnt << '\n';
    return 0;
}