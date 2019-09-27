// 감시
// https://www.acmicpc.net/problem/15683
#include <bits/stdc++.h>
using namespace std;
int N, M, cctvSize, result;
int board[8][8];
struct CCTV
{
    int type, y, x;
};
CCTV cctv[8];
// cctv 회전
const int cctvRotate[5] = {4, 2, 4, 4, 1};
void update(int dir, CCTV cctv)
{
    dir = (dir % 4);
    // 4방향
    // 북
    if (dir == 0)
    {
        for (int y = cctv.y - 1; y >= 0; y--)
        {
            if (board[y][cctv.x] == 6)
                break;
            board[y][cctv.x] = -1;
        }
    }
    else if (dir == 1)
    {
        for (int x = cctv.x + 1; x < M; x++)
        {
            if (board[cctv.y][x] == 6)
                break;
            board[cctv.y][x] = -1;
        }
    }
    else if (dir == 2)
    {
        for (int y = cctv.y + 1; y < N; y++)
        {
            if (board[y][cctv.x] == 6)
                break;
            board[y][cctv.x] = -1;
        }
    }
    else if (dir == 3)
    {
        for (int x = cctv.x - 1; x >= 0; x--)
        {
            if (board[cctv.y][x] == 6)
                break;
            board[cctv.y][x] = -1;
        }
    }
}
void boardCopy(int now[8][8], int next[8][8])
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            next[y][x] = now[y][x];
        }
    }
}
void dfs(int index)
{
    if (index == cctvSize)
    {
        int cnt = 0;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (board[y][x] == 0)
                    cnt += 1;
            }
        }

        result = min(result, cnt);
        return;
    }

    int backUp[8][8];
    int type = cctv[index].type; // cctv 타입
    // 얼마나 회전 할지 선택
    for (int dir = 0; dir < cctvRotate[type]; dir++)
    {
        boardCopy(board, backUp);
        if (type == 0)
        {
            update(dir, cctv[index]);
        }
        else if (type == 1)
        {
            // 기본, 180도
            update(dir, cctv[index]);
            update(dir + 2, cctv[index]);
        }
        else if (type == 2)
        {
            // 기본, 90도, 180도
            update(dir, cctv[index]);
            update(dir + 1, cctv[index]);
        }
        else if (type == 3)
        {
            // 전체 회전
            update(dir, cctv[index]);
            update(dir + 1, cctv[index]);
            update(dir + 2, cctv[index]);
        }
        else if (type == 4)
        {
            // 전체 회전
            update(dir, cctv[index]);
            update(dir + 1, cctv[index]);
            update(dir + 2, cctv[index]);
            update(dir + 3, cctv[index]);
        }
        dfs(index + 1); // CCTV 갯수 증가
        boardCopy(backUp, board);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    cctvSize = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
            if (board[y][x] >= 1 && board[y][x] <= 5)
            {
                cctv[cctvSize].y = y;
                cctv[cctvSize].x = x;
                cctv[cctvSize].type = board[y][x] - 1;
                cctvSize += 1;
            }
        }
    }

    result = 987654321;
    dfs(0);
    cout << result << '\n';
    return 0;
}