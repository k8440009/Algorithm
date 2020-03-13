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
    // 윗 공기 청정기
    // 왼쪽
    for (int r = y - 1; r - 1 >= 0; r--)
    {
        board[r][0] = board[r - 1][0];
    }
    //위
    for (int c = 0; c + 1 < C; c++)
    {
        board[0][c] = board[0][c + 1];
    }
    // 오른쪽
    for (int r = 0; r + 1 <= y; r++)
    {
        board[r][C - 1] = board[r + 1][C - 1];
    }
    // 아래
    for (int c = C - 1; c - 1 >= 1; c--)
    {
        board[y][c] = board[y][c - 1];
    }
    board[y][x + 1] = 0;
    // 아랫 공기
    y = cleaner[1].first;
    x = cleaner[1].second;
    // 왼쪽
    for (int r = y + 1; r + 1 < R; r++)
    {
        board[r][0] = board[r + 1][0];
    }
    // 아래
    for (int c = 0; c + 1 < C; c++)
    {
        board[R - 1][c] = board[R - 1][c + 1];
    }
    // 오른쪽
    for (int r = R - 1; r - 1 >= y; r--)
    {
        board[r][C - 1] = board[r - 1][C - 1];
    }
    // 위
    for (int c = C - 1; c - 1 >= 1; c--)
    {
        board[y][c] = board[y][c - 1];
    }
    board[y][x + 1] = 0;
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
                int value = 0; // 확산되는 곳
                for (int dir = 0; dir < 4; dir++)
                {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];

                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] == -1)
                        continue;

                    dust[nr][nc] += spreadDust;
                    value += spreadDust;
                }
                dust[r][c] += (board[r][c] - value);
            }
        }
    }

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {

            if (board[r][c] == -1)
            {
                dust[r][c] = -1;
                continue;
            }
            else
            {
                board[r][c] = dust[r][c];
                dust[r][c] = 0;
            }
        }
    }
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

    int answer = 0;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (board[r][c] == -1)
                continue;
            answer += board[r][c];
        }
    }
    cout << answer << '\n';

    return 0;
}