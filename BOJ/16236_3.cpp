// 아기 상어
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 20 + 1;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
struct FISH
{
    int y, x, time;
};
FISH shark;
int sharkSize, sharkEat;
int board[MAX][MAX];
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == 9)
            {
                shark.y = y, shark.x = x, shark.time = 0;
                sharkSize = 2, sharkEat = 0;
                board[y][x] = 0;
            }
        }
    }

    bool isUpdate = true;
    while (isUpdate)
    {
        isUpdate = false;
        bool visited[MAX][MAX];
        fill_n(visited[0], MAX * MAX, 0);
        queue<FISH> q;
        visited[shark.y][shark.x] = true;
        q.push(shark);

        FISH candi;
        candi.y = 20, candi.time = -1;

        while (!q.empty())
        {
            FISH cur = q.front();
            q.pop();

            if (candi.time != -1 && candi.time < cur.time)
            {
                break;
            }
            if (board[cur.y][cur.x] < sharkSize && board[cur.y][cur.x] != 0)
            {
                isUpdate = true;
                if (candi.y > cur.y || (candi.y == cur.y) && candi.x > cur.x)
                {
                    candi = cur;
                }
            }

            for (int dir = 0; dir < 4; dir++)
            {
                FISH next;
                next.y = cur.y + dy[dir];
                next.x = cur.x + dx[dir];
                next.time = cur.time + 1;

                if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N)
                    continue;
                if (!visited[next.y][next.x] && sharkSize >= board[next.y][next.x])
                {
                    visited[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }

        if (isUpdate)
        {
            shark = candi;
            sharkEat += 1;
            if (sharkEat == sharkSize)
            {
                sharkSize += 1;
                sharkEat = 0;
            }
            board[shark.y][shark.x] = 0;
        }
    }

    cout << shark.time << '\n';
    return 0;
}