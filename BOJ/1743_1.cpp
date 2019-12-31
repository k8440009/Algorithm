// 음식물 피하기
// https://www.acmicpc.net/problem/1743
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100 + 1;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
int N, M, K, board[MAX][MAX];
bool visited[MAX][MAX];
int dfs(int y, int x)
{
    int cnt = 1;
    visited[y][x] = true;
    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (ny < 1 || ny > N || nx < 1 || nx > M || visited[ny][nx])
            continue;
        if (board[ny][nx] == 1)
            cnt += dfs(ny, nx);
    }
    return cnt;
}
void init()
{
    cin >> N >> M >> K;
    int y, x;
    for (int i = 0; i < K; i++)
    {
        cin >> y >> x;
        board[y][x] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int answer = 0;
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= M; x++)
            if (board[y][x] == 1 && !visited[y][x])
                answer = max(answer, dfs(y, x));
    cout << answer;
    return 0;
}