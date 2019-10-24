// Two Dots
// https://www.acmicpc.net/problem/16929
#include <iostream>
#include <string>
using namespace std;
const int MAX = 50;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N, M, sy, sx;
char board[MAX][MAX];
bool check = false;
bool visited[MAX][MAX];
void dfs(int y, int x, int cnt, char color)
{
    if (check)
        return;

    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir], nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        // 방문 안 한 경우
        if (!visited[ny][nx])
        {
            if (board[ny][nx] == color)
            {
                visited[ny][nx] = true;
                dfs(ny, nx, cnt + 1, color);
            }
        }
        // 방문 한경우
        else
        {
            if (cnt >= 4 && ny == sy && nx == sx)
            {
                check = true;
                return;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> board[i];

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            fill_n(visited[0], MAX * MAX, 0);
            visited[y][x] = true;
            int cnt = 1;
            sy = y, sx = x;
            dfs(y, x, cnt, board[y][x]); // y,x,갯수, color
            if (check)
            {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }

    cout << "No" << '\n';
    return 0;
}