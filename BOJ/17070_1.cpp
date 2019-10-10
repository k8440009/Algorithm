// 파이프 옮기기 1
// https://www.acmicpc.net/problem/17070
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 16;
int N;
int answer;
int board[MAX][MAX];
int dy[3] = {0, 1, 1};
int dx[3] = {1, 0, 1};
void dfs(int y, int x, int pipe)
{
    if (y == N - 1 && x == N - 1)
    {
        answer += 1;
        return;
    }

    for (int dir = 0; dir < 3; dir++)
    {
        // 가로 -> 세로, 세로 -> 가로 불가능
        if ((dir == 0 && pipe == 1) || (dir == 1 && pipe == 0))
            continue;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 1)
            continue;
        // 대각선인 경우 확인 해야할 벽
        if (dir == 2 && ((board[y][x + 1] == 1) || board[y + 1][x] == 1))
            continue;
        dfs(ny, nx, dir);
    }
}
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
        }
    }

    // 끝점과, 방향 저장
    dfs(0, 1, 0);

    cout << answer << '\n';
    return 0;
}