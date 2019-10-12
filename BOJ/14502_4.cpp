// 연구소
// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 8;
int N, M, answer = 0;
int board[MAX][MAX];
int practice[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> virus;
void activeVirus()
{
    bool visited[MAX][MAX];
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            practice[y][x] = board[y][x];
            visited[y][x] = false;
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++)
    {
        q.push(make_pair(virus[i].first, virus[i].second));
        visited[virus[i].first][virus[i].second] = true;
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

            if (practice[ny][nx] != 1)
            {
                practice[ny][nx] = 2;
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }

    int cnt = 0; // 빈칸 갯수
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (practice[y][x] == 0)
                cnt += 1;

    answer = max(answer, cnt);
}
void dfs(int cnt, int sy, int sx)
{
    // 바이러스 확산
    if (cnt == 3)
    {
        activeVirus();
        return;
    }

    for (int y = sy; y < N; y++)
    {
        for (int x = sx; x < M; x++)
        {
            if (board[y][x] == 0)
            {
                board[y][x] = 1;
                dfs(cnt + 1, y, x);
                board[y][x] = 0;
            }
        }
        sx = 0;
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
            if (board[y][x] == 2)
                virus.push_back(make_pair(y, x));
        }
    }

    // 벽 세움
    // cnt, y,x
    dfs(0, 0, 0);

    cout << answer << '\n';
    return 0;
}