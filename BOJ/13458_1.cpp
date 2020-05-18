// 시험 감독
// https://www.acmicpc.net/problem/13458
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
int N, B, C;
vector<int> room;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    room.resize(N);
    for (int i = 0; i < N; i++)
        cin >> room[i];
    cin >> B >> C; // 시험장 갯수, 총감독관, 부감독관

    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        answer += 1;
        int student = room[i] - B;
        // 부감독관 필요한 경우
        if (student > 0)
        {
            if (C > student)
                answer += 1;
            else
            {
                int add = student / C;
                if (student % C == 0)
                    answer += add;
                else
                    answer += (add + 1);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}