// 유기농 배추
// https://www.acmicpc.net/problem/1012
#include <iostream>
using namespace std;
const int MAX = 50;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
int TC, M, N, K, board[MAX][MAX];
bool visited[MAX][MAX];
void dfs(int y, int x)
{
    visited[y][x] = true;
    // 기저 주변 부분을 이동 할 수 없는 경우
    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
            continue;
        if (board[ny][nx] == 1)
            dfs(ny, nx);
    }
}
void init()
{
    fill_n(visited[0], MAX * MAX, 0);
    fill_n(board[0], MAX * MAX, 0);
    cin >> M >> N >> K;
    int y, x;
    for (int k = 0; k < K; k++)
    {
        cin >> x >> y;
        board[y][x] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
    for (int ts = 1; ts <= TC; ts++)
    {
        // 입력
        init();
        int cnt = 0;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (board[y][x] == 1 && !visited[y][x])
                {
                    dfs(y, x);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
}