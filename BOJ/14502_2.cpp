// 연구소
// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 8;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
int N, M, answer = 0;
int board[MAX][MAX];
int practice[MAX][MAX];
bool selected[MAX * MAX];
vector<pair<int, int>> wall;

void active()
{
    bool visited[MAX][MAX];
    queue<pair<int, int>> q;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            practice[y][x] = board[y][x];
            visited[y][x] = false;
            if (practice[y][x] == 2)
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
            if (practice[ny][nx] == 0)
            {
                practice[ny][nx] = 2;
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }

    int safe = 0;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (practice[y][x] == 0)
                safe += 1;

    answer = max(answer, safe);
    return;
}
void dfs(int cnt, int r, int c)
{
    if (cnt == 3)
    {
        active();
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