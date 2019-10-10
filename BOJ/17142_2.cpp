// 연구소 3
// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int INF = 987654321;
int N, M, blank, answer = INF;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int board[MAX][MAX];
int practice[MAX][MAX];
vector<pair<int, int>> pick;
void activeVirus()
{
    int time = 0, infect = 0;
    int dist[MAX][MAX];

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            practice[y][x] = board[y][x];
            dist[y][x] = -1;
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < pick.size(); i++)
    {
        int y = pick[i].first;
        int x = pick[i].second;
        q.push(make_pair(y, x));
        dist[y][x] = 0;
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int y = cur.first;
        int x = cur.second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (dist[ny][nx] == -1 && practice[ny][nx] != 1)
            {
                dist[ny][nx] = dist[y][x] + 1;
                if (practice[ny][nx] == 0)
                {
                    infect += 1;
                    time = dist[ny][nx];
                }

                q.push(make_pair(ny, nx));
            }
        }
    }

    if (infect == blank)
        answer = min(answer, time);
    return;
}
void dfs(int cnt, int r, int c)
{
    if (cnt == M)
    {
        activeVirus();
        return;
    }

    for (int y = r; y < N; y++)
    {
        for (int x = c; x < N; x++)
        {
            if (board[y][x] == 2)
            {
                pick.push_back(make_pair(y, x));
                dfs(cnt + 1, y, x);
                pick.pop_back();
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
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == 0)
                blank += 1;
        }
    }
    // cnt, y,x
    dfs(0, 0, 0);
    if (answer == INF)
        answer = -1;
    cout << answer << '\n';
    return 0;
}