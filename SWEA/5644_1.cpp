// 5644. [모의 SW 역량테스트] 무선 충전
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int dy[5] = {0, -1, 0, 1, 0};
const int dx[5] = {0, 0, 1, 0, -1};
struct BECON
{
    // 위치, 범위, 성능, 사용 여부
    int y, x, coverage, perform, used;
};
struct USER
{
    int y, x;
};
BECON becon[8];
USER user[2];
int M, A; // 총 이동 시간, 비콘
int board[10][10];
int moving[MAX][MAX];
int ret = 0;
bool check(int a, int b)
{
    int dist = abs(user[a].y - becon[b].y) + abs(user[a].x - becon[b].x);
    return dist <= becon[b].coverage;
}
void dfs(int user, int data)
{
    if (user == 2)
    {
        ret = max(ret, data);
        return;
    }

    for (int i = 0; i < A; i++)
    {
        if (!becon[i].used && check(user, i))
        {
            becon[i].used = 1;
            dfs(user + 1, data + becon[i].perform);
            becon[i].used = 0;
        }
    }

    dfs(user + 1, data);
}
int count()
{
    ret = 0;
    dfs(0, 0);
    return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> M >> A; // 이동 시간, 비콘의 갯수
        // 사용자의 이동 정보
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> moving[i][j];
            }
        }
        // 비콘 정보 저장
        for (int i = 0; i < A; i++)
        {
            cin >> becon[i].y >> becon[i].x >> becon[i].coverage >> becon[i].perform;
            becon[i].used = 0;
        }

        user[0].y = 1, user[0].x = 1;
        user[1].y = 10, user[1].x = 10;

        int answer = 0;
        answer = 0;
        // 경로를 따라 이동
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                user[j].y += dy[moving[j][i]];
                user[j].x += dx[moving[j][i]];
            }
            answer = 0;
        }
        cout << "#" << ts << ' ' << answer << '\n';

        return 0;
    }
