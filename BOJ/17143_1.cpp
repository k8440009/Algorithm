// 낚시왕
// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct SHARK
{
    int r, c, s, d, z;
};
const int MAX = 100;
int R, C, M;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
vector<SHARK> board[MAX][MAX];
void move()
{
    queue<SHARK> q;

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (!board[r][c].empty())
            {
                q.push(board[r][c][0]);
                board[r][c].clear();
            }
        }
    }

    while (!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        int speed = q.front().s;
        int dir = q.front().d;
        int size = q.front().z;
        q.pop();

        // 속도만큼 움직임
        for (int i = 0; i < speed; i++)
        {
            // 위 아래
            if (dir == 0 || dir == 1)
            {
                int nr = r + dr[dir];
                if (nr < 0 || nr >= R)
                    dir = 1 - dir;
                r += dr[dir];
            }
            // 왼쪽, 오른쪽
            else
            {
                int nc = c + dc[dir];
                if (nc < 0 || nc >= C)
                    dir = 5 - dir;
                c += dc[dir];
            }
        }

        // 계산 완료
        SHARK sh;
        sh.r = r;
        sh.c = c;
        sh.s = speed;
        sh.d = dir;
        sh.z = size;

        if (board[r][c].size())
        {
            // 해당칸에 있는 상어크기 보다 더 큰 경우
            if (size > board[r][c][0].z)
            {
                board[sh.r][sh.c].clear();
                board[sh.r][sh.c].push_back(sh);
            }
        }
        else
        {
            board[sh.r][sh.c].push_back(sh);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++)
    {
        SHARK sh;
        // 행,열,속력,이동방향,크기
        cin >> sh.r >> sh.c >> sh.s >> sh.d >> sh.z;
        sh.r -= 1;
        sh.c -= 1;
        sh.d -= 1;
        board[sh.r][sh.c].push_back(sh);
    }

    int answer = 0;
    int cur = -1;
    for (int time = 0; time < C; time++)
    {
        cur += 1;

        for (int r = 0; r < R; r++)
        {
            // 1. 사냥
            if (!board[r][cur].empty())
            {
                answer += board[r][cur][0].z;
                board[r][cur].clear();
                break;
            }
            // 2. 움직임
        }
        move();
    }

    cout << answer << '\n';

    return 0;
}