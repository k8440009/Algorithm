// 용액
// https://www.acmicpc.net/problem/2467
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> num;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    num.resize(N);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    int start = 0, end = N - 1, result = 2e9;
    pair<int, int> answer;
    while (start < end)
    {
        int a = num[start];
        int b = num[end];
        if (abs(a + b) < result)
        {
            result = abs(a + b);
            answer.first = a, answer.second = b;
        }

        if (a + b < 0)
            start++;
        else
            end--;
    }

    cout << answer.first << ' ' << answer.second;
    return 0;
}