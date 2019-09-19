// 약수
// https://www.acmicpc.net/problem/1037
/*
    제일 작은 약수 * 제일 큰 약수
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long result = 1;

    result = v[0] * v[n - 1];

    cout << result << '\n';
    return 0;
}