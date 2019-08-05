// 개 수 세기
// https://www.acmicpc.net/problem/10807
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    int v;
    cin >> v;

    int cnt = count(vec.begin(), vec.end(), v);
    cout << cnt << '\n';
}