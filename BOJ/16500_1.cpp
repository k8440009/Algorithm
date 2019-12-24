// 문자열 판별
// https://www.acmicpc.net/problem/16500
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100 + 1;
int N;
vector<string> A;
string S;
int cache[MAX];
// 시작위치를 받아서 true, false 체크
bool classify(int pos)
{
    int &ret = cache[pos];
    if (ret != -1)
        return ret;
    if (pos == S.size()) // 정답인 경우
        return ret = 1;
    ret = 0;
    for (int i = 0; i < N; i++)
    {
        string M = S.substr(pos, A[i].size());
        if (A[i] == M)
        {
            ret |= classify(pos + A[i].size());
        }
    }
    return ret;
}
void init()
{
    fill_n(cache, MAX, -1);
    cin >> S >> N;
    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << classify(0);

    return 0;
}
