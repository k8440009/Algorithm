// 가장 긴 증가하는 부분 수열 3
// https://www.acmicpc.net/problem/12738
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1000000 + 1, INF = 1000000000 + 1;
int N, S[MAX];
vector<int> sub;
int LIS()
{
    int answer = 0;
    sub.push_back(-INF);
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
    return answer;
}
void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int answer = LIS();
    cout << answer << '\n';
}

/*
    참고
    https://jason9319.tistory.com/113
*/