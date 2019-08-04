#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int LIS = 0;
    vector<int> d(n);

    for (int i = 0; i < n; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && d[i] < d[j] + 1)
            {
                d[i] = d[j] + 1;
            }
        }
        LIS = max(LIS, d[i]);
    }

    cout << LIS << '\n';

    return 0;
}