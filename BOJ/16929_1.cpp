// Two Dots
// https://www.acmicpc.net/problem/16929
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 50;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, sy, sx;
char board[MAX][MAX];
bool visited[MAX][MAX];
bool check = false;
// dfs하면서 사이클 판단
void dfs(int y, int x, int cnt, char color)
{
    if (check)
        return;

    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        if (!visited[ny][nx])
        {
            if (color == board[ny][nx])
            {
                visited[ny][nx] = true;
                dfs(ny, nx, cnt + 1, color);
            }
        }
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

    cin >> N >> M; // 가로 세로

    for (int i = 0; i < N; i++)
        cin >> board[i];

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            // 모든 점 DFS
            fill_n(visited[0], MAX * MAX, 0);
            sy = y, sx = x;
            visited[y][x] = true;
            dfs(y, x, 1, board[y][x]);

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