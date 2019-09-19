/*
#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
int R, C, T;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {-1, 1, 0, 0};
int cw[4] = {2, 1, 3, 0};
int ccw[4] = {2, 0, 3, 1};
int board[MAX][MAX];
vector<pair<int, int>> cleaner;
void wind(int index)
{
    if (index == 0)
    {
        int y = cleaner[index].first;

        while (true)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nX = x + dx[ccw[dir]];
                int nY = y dy[ccw[dir]];
            }
        }
    }
    else
    {
    }
}
void dust(int r, int c)
{
    queue<pair<int, int>> q;

    for (int dir = 0; dir < 4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;
        if (board[nc][nr] == -1)
            continue;
        q.push({nr, nc});
    }

    int spread = board[r][c] / 5;
    board[r][c] = board[r][c] - spread * q.size();

    while (!q.empty())
    {
        int nr = q.front().first;
        int nc = q.front().second;
        board[nr][nc] = spread;
    }
}
int main()
{
    cin >> R >> C >> T;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> board[r][c];
            if (board[r][c] == -1)
                cleaner.push_back({r, c});
        }
    }

    for (int time = 1; time <= T; time++)
    {
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (board[r][c] == 0)
                    continue;
                dust(r, c);
                wind(0);
                wind(1);
            }
        }
    }
    return 0;
}
*/