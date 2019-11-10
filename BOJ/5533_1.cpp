// 유니크
// https://www.acmicpc.net/problem/5533
#include <iostream>
#include <map>
using namespace std;
const int MAX = 200 + 1;
int N;
int scores[MAX][3]; // 점수판
int player[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // 점수판
    for (int i = 0; i < N; i++)
        cin >> scores[i][0] >> scores[i][1] >> scores[i][2];

    // 회차
    for (int i = 0; i < 3; i++)
    {
        map<int, int> hashing; // 점수, 횟수
        // 플레이어 점수
        for (int j = 0; j < N; j++)
        {
            int point = scores[j][i];
            hashing[point]++;
        }

        for (int j = 0; j < N; j++)
        {
            int point = scores[j][i];
            if (hashing.find(point)->second == 1)
                player[j] += point;
        }
    }

    for (int i = 0; i < N; i++)
        cout << player[i] << '\n';

    return 0;
}