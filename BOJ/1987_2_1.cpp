// 알파벳
// https://www.acmicpc.net/problem/1987
#include <iostream>
using namespace std;
const int MAX = 20 + 1;
const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};
int R, C, answer;
char board[MAX][MAX];
bool alpha[26];
void dfs(int r, int c, int cnt)
{
    if (cnt > answer)
        answer = cnt;

    for (int dir = 0; dir < 4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C || alpha[board[nr][nc] - 'A'])
            continue;

        char next = board[nr][nc] - 'A';
        alpha[next] = true;
        dfs(nr, nc, cnt + 1);
        alpha[next] = false;
    }
}
void init()
{
    cin >> R >> C;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> board[r][c];
    alpha[board[0][0] - 'A'] = true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    dfs(0, 0, 1);
    cout << answer << '\n';
    return 0;
}