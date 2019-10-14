// 5644. [모의 SW 역량테스트] 무선 충전
/*
#include <iostream>
using namespace std;
struct BECON
{
    // 위치, 범위, 성능, 사용 여부
    int y, x;
    int coverage;
    int perform;
    int u;
};
struct PEOPLE
{
    int y, x;
};

const int MAX = 100;
BECON becon[8];
PEOPLE people[2];
int peopleMove[2][MAX];
int M, N;
const int dy[5] = {0, -1, 0, 1, 0};
const int dx[5] = {0, 0, 1, 0, -1};
// becon 범위 있는지 확인
bool check(int a, int b)
{
    int dist = abs(people[a].y - people[b].y) + abs(people[a].x - people[b].x);
    return dist <= becon[b].coverage;
}
int main()
{
    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> M >> N; // 이동 시간, 비콘의 갯수
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> peopleMove[i][j];
            }
        }
        // 비콘
        for (int i = 0; i < N; i++)
        {
            cin >> becon[i].y >> becon[i].x >> becon[i].coverage >> becon[i].perform;
            becon[i].u = 0;
        }
        // people
        people[0].y = 0, people[0].x = 0;
        people[1].y = 9;
        people[0].x = 9;
    }

    int answer = 0;
    answer += count();
    for(int i = 0; i < M; i++){
        for(int j =0;j < 2; j++){
            people[j].y = dy[peopleMove[j][i]];
            people[i].x = dx[peopleMove[j][i]];
        }
    }

    return 0;
}
*/