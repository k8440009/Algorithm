// 연구소
// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 8;
int N, M, answer = 0;
int board[MAX][MAX];
int pratice[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
void activeVirus()
{
    bool visited[MAX][MAX];
    queue<pair<int, int>> q;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            pratice[y][x] = board[y][x];
            visited[y][x] = false;
            if (board[y][x] == 2)
            {
                q.push(make_pair(y, x));
                visited[y][x] = true;
            }
        }
    }

    while (!q.empty())
    {

        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
                continue;
            if (pratice[ny][nx] == 0)
            {
                pratice[ny][nx] = 2;
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }

    int cnt = 0;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (pratice[y][x] == 0)
            {
                cnt += 1;
            }
        }
    }
    // 안전 영역 최대 크기
    answer = max(answer, cnt);
}
void dfs(int cnt, int r, int c)
{
    if (cnt == 3)
    {
        activeVirus();
        return;
    }
    for (int y = r; y < N; y++)
    {
        for (int x = c; x < M; x++)
        {
            if (board[y][x] == 0)
            {
                board[y][x] = 1;
                dfs(cnt + 1, y, x);
                board[y][x] = 0;
            }
        }

        c = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
        }
    }
    // cnt, y,x
    dfs(0, 0, 0);
    cout << answer << '\n';
    return 0;
}