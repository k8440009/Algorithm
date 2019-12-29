// 가장 긴 증가하는 부분 수열 4
// https://www.acmicpc.net/problem/14002
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1000 + 1;
int N, cache[MAX], S[MAX], choices[MAX];
vector<int> seq;
// S[start]에서 증가 부분 수열 중 최대 길이 반환
int LIS(int start)
{
    int &ret = cache[start + 1];
    if (ret != -1)
        return ret;
    ret = 1; // 기본이 길이가 1
    int bestNext = -1;
    for (int next = start + 1; next < N; next++)
    {
        // 시작점이 -1 이거나, 배열의 값이 다음 배열의 값보다 큰 경우
        if (start == -1 || S[start] < S[next])
        {
            int cand = LIS(next) + 1;
            if (cand > ret)
            {
                ret = cand;
                bestNext = next;
            }
        }
    }
    choices[start + 1] = bestNext;
    return ret;
}
void reconstruct(int start)
{
    if (start != -1)
        seq.push_back(S[start]);
    int next = choices[start + 1];
    if (next != -1)
        reconstruct(next);
}
void init()
{
    fill_n(cache, MAX, -1);
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
    int answer = LIS(-1) - 1;
    reconstruct(-1);
    cout << answer << '\n';
    for (vector<int>::iterator iter = seq.begin(); iter != seq.end(); iter++)
        cout << *iter << ' ';
    return 0;
}