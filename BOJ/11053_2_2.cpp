// 가장 긴 증가하는 부분 수열 O(NlogN)
// https://www.acmicpc.net/problem/11053
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000 + 1, INF = 987654321;
int N, S[MAX];
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
/*
    참고
    https://jason9319.tistory.com/113
*/