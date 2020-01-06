// 알파벳
// https://www.acmicpc.net/problem/1987
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool visited[26];
char board[20][20];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;
int answer = 0;
void dfs(int y, int x, int cnt)
{
    answer = max(answer, cnt);

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= c || ny < 0 || ny >= r)
            continue;

        int k = board[ny][nx] - 'A';
        if (visited[k])
            continue;

        visited[k] = true;
        dfs(ny, nx, cnt + 1);
        visited[k] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }

    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << answer << '\n';
    return 0;
}