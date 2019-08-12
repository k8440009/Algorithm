// 연산자 끼워 넣기 2
// https://www.acmicpc.net/problem/15658
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int MAX = -INF;
int MIN = INF;
vector<int> a;
void recursion(int index, int now, int plus, int minus, int mul, int div)
{
    if (index == a.size())
    {
        if (now > MAX)
            MAX = now;
        if (now < MIN)
            MIN = now;
        return;
    }

    if (plus > 0)
        recursion(index + 1, now + a[index], plus - 1, minus, mul, div);
    if (minus > 0)
        recursion(index + 1, now - a[index], plus, minus - 1, mul, div);
    if (mul > 0)
        recursion(index + 1, now * a[index], plus, minus, mul - 1, div);
    if (div > 0)
        recursion(index + 1, now / a[index], plus, minus, mul, div - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;

    recursion(1, a[0], plus, minus, mul, div);

    cout << MAX << '\n';
    cout << MIN << '\n';
    return 0;
}