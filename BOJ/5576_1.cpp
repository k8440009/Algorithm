// 콘테스트
// https://www.acmicpc.net/problem/5576
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> w(10), k(10);
    for (int i = 0; i < 10; i++)
        cin >> w[i];
    for (int i = 0; i < 10; i++)
        cin >> k[i];

    // 오름 차순
    sort(w.begin(), w.end(), greater<int>());
    sort(k.begin(), k.end(), greater<int>());

    cout << w[0] + w[1] + w[2] << ' ' << k[0] + k[1] + k[2];

    return 0;
}