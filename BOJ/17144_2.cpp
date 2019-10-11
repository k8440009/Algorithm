// 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R, C, T;
const int MAX = 50 + 1;
int board[MAX][MAX];
int dust[MAX][MAX];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pair<int, int>> cleaner;
void active()
{
    int y = cleaner[0].first;
    int x = cleaner[0].second;
    // 아래
    for (int r = 0; r < y; r++)
    {
        board[r + 1][0] = board[r][0];
    }
    // 오른쪽
    for (int c = 1; c < C; c++)
    {
        board[y + 1][c] = board[y][c];
    }
    // 위
    // 왼쪽
}
void spread()
{
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (board[r][c] > 0)
            {
                int spreadDust = board[r][c] / 5;
                int cnt = 0; // 확산되는 곳
                for (int dir = 0; dir < 4; dir++)
                {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];

                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] == -1)
                        continue;

                    dust[nr][nc] += spreadDust;
                    cnt += 1;
                }
                dust[r][c] = spreadDust - (spreadDust)*cnt;
            }
        }
    }

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            board[r][c] = dust[r][c];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> T;
    cleaner.resize(2);
    int index = 0;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> board[r][c];
            if (board[r][c] == -1)
            {
                cleaner[index].first = r;
                cleaner[index].second = c;
                index += 1;
                dust[r][c] = -1;
            }
        }
    }

    for (int time = 0; time < T; time++)
    {
        spread();
        active();
    }
    return 0;
}