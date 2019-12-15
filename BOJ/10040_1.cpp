// 투표
// https://www.acmicpc.net/problem/10040
#include <iostream>
using namespace std;
const int MAX = 1000 + 1;
int N, M;
int sports[MAX];
int vote[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> sports[i];

    for (int j = 1; j <= M; j++)
    {
        int cost;
        cin >> cost;
        for (int i = 1; i <= N; i++)
            if (sports[i] <= cost)
            {
                vote[i]++;
                break;
            }
    }

    //for (int i = 1; i <= N; i++)
    //   cout << sports[i] << ' ' << vote[i] << '\n';

    int maxCount = 0;
    int maxNum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (vote[i] > maxCount)
        {
            maxCount = vote[i];
            maxNum = i;
        }
    }

    cout << maxNum;

    return 0;
}