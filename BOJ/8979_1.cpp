// 올림픽
// https://www.acmicpc.net/problem/8979
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
const int MAX = 1000 + 1;
struct SCORE
{
    int nation, gold, sliver, bronze;
};
vector<SCORE> olympic(MAX);
bool cmp(SCORE &a, SCORE &b)
{
    // 금
    if (a.gold > b.gold)
        return true;
    else if (a.gold == b.gold)
    {
        // 은
        if (a.sliver > b.sliver)
            return true;
        else if (a.sliver == b.sliver)
        {
            // 동
            if (a.bronze > b.bronze)
                return true;
            else if (a.bronze == b.bronze)
            {
                if (a.nation == K)
                    return true;
                else if (b.nation == K)
                    return false;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> olympic[i].nation >> olympic[i].gold >> olympic[i].sliver >> olympic[i].bronze;

    sort(olympic.begin(), olympic.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        if (olympic[i].nation == K)
            cout << i + 1 << '\n';
    }

    return 0;
}