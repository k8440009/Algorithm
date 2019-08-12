// 연산자 끼워 넣기
// https://www.acmicpc.net/problem/14888
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 수의 갯수
    int n;
    cin >> n;
    // 숫자들
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // 연산자
    // + : 0, - : 1, * : 2, / : 3
    vector<int> b;
    for (int i = 0; i < 4; i++)
    {
        int cnt = 0;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
            b.push_back(i);
    }

    sort(b.begin(), b.end());

    int totalMax = -INF;
    int totalMin = INF;

    do
    {
        int total = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (b[i - 1] == 0)
            {
                total += a[i];
            }
            else if (b[i - 1] == 1)
            {
                total -= a[i];
            }
            else if (b[i - 1] == 2)
            {
                total *= a[i];
            }
            else
            {
                total /= a[i];
            }
        }
        totalMax = max(totalMax, total);
        totalMin = min(totalMin, total);
    } while (next_permutation(b.begin(), b.end()));

    cout << totalMax << '\n';
    cout << totalMin << '\n';
}