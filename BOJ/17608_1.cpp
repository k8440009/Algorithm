// 막대기
// https://www.acmicpc.net/problem/17608
#include <iostream>
using namespace std;
const int MAX = 100000 + 1;
int N;
int height[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> height[i];
    }

    int cnt = 1;
    int criteria = height[N];
    for (int i = N - 1; i >= 1; i--)
    {
        if (height[i] > criteria)
        {
            cnt++;
            criteria = height[i];
        }
    }

    cout << cnt << '\n';

    return 0;
}