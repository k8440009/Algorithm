// 가장 긴 증가하는 부분 수열 2 O(NlogN), 이분탐색
// https://www.acmicpc.net/problem/12015
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000 + 1, INF = 987654321;
int N, cache[MAX], S[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
    vector<int> sub;
    sub.push_back(-INF);
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        if (sub.back() < S[i])
        {
            sub.push_back(S[i]);
            answer++;
        }
        else
        {
            vector<int>::iterator it = lower_bound(sub.begin(), sub.end(), S[i]);
            *it = S[i];
        }
    }

    cout << answer << '\n';

    return 0;
}