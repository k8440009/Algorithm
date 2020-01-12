// 탈출
// https://www.acmicpc.net/problem/3055
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50 + 1, INF = 987654321;
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
int R, C, sr, sc, wr, wc, answer = INF;
char board[MAX][MAX];
int visitedCosm[MAX][MAX], visitedWater[MAX][MAX];
struct Parameter
{
    int r, c, time = 0;
};

Parameter cosm, water;
queue<Parameter> a;

void bfs()
{
    // 물 bfs해서 시간 체크 -> 고슴도치 bfs해서 시간 체크
    // 물
    while (!a.empty())
    {
        Parameter cur = a.front();
        a.pop();
        // 이동
        for (int dir = 0; dir < 4; dir++)
        {
            int nr = cur.r + dr[dir], nc = cur.c + dc[dir], nt = cur.time + 1;
            if (nr < 0 || nr >= R || nc < 0 || nc >= C || visitedWater[nr][nc] || board[nr][nc] == 'X' || board[nr][nc] == 'D')
                continue;

            water.r = nr, water.c = nc, water.time = nt;
            visitedWater[nr][nc] = nt;
            a.push(water);
        }
    }
    // 고슴도치
    queue<Parameter> b;
    b.push(cosm);
    visitedCosm[cosm.r][cosm.c] = cosm.time;
    while (!b.empty())
    {
        Parameter cur = b.front();
        b.pop();
        // 이동
        for (int dir = 0; dir < 4; dir++)
        {
            int nr = cur.r + dr[dir], nc = cur.c + dc[dir], nt = cur.time + 1;
            if (nr < 0 || nr >= R || nc < 0 || nc >= C || visitedCosm[nr][nc] || board[nr][nc] == 'X')
                continue;
            // 물이 아직 도착하지 않은 경우
            if (visitedWater[nr][nc] == 0 || visitedWater[nr][nc] > nt)
            {
                cosm.r = nr, cosm.c = nc, cosm.time = nt;
                visitedCosm[nr][nc] = nt;
                b.push(cosm);
            }
            // 동굴
            if (board[nr][nc] == 'D')
                answer = min(answer, nt);
        }
    }
}
void init()
{
    cin >> R >> C;
    fill_n(visitedCosm[0], MAX * MAX, 0);
    fill_n(visitedWater[0], MAX * MAX, 0);
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
        {
            cin >> board[r][c];
            if (board[r][c] == 'S')
            {
                cosm.r = r, cosm.c = c, cosm.time = 1;
                board[r][c] = '.';
            }
            else if (board[r][c] == '*')
            {
                water.r = r, water.c = c, water.time = 1;
                board[r][c] = '.';
                a.push(water);
                visitedWater[water.r][water.c] = water.time;
            }
        }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    bfs();
    /*
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
            cout << visitedWater[r][c] << ' ';
        cout << '\n';
    }
    cout << '\n';
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
            cout << visitedCosm[r][c] << ' ';
        cout << '\n';
    }
    */
    if (answer == INF)
        cout << "KAKTUS" << '\n';
    else
        cout << answer - 1 << '\n';

    return 0;
}
/*
    과정
    시도 1)
    물 BFS -> 고슴도치 BFS
    시도 1_1)
    물이 여러 지점이라는 조건을 빼먹음
    시도 1_2)
    물이 방문하지 않은 지점을 고려하지 않음

    내가 문제를 스스로 이해하고 재정의 -> 어느정도 코딩하면서 논리를 수정하도록하자
*/