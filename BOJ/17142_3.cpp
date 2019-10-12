// 연구소 3
// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int INF = 987654321;
int N, M, safe, answer = INF;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int board[MAX][MAX];
bool selected[10];
vector<pair<int, int>> virus;
void activeVirus()
{
    int time = 0, infect = 0;
    int dist[MAX][MAX];
    fill_n(dist[0], MAX * MAX, -1);

    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++)
    {
        if (selected[i])
        {
            q.push(make_pair(virus[i].first, virus[i].second));
            dist[virus[i].first][virus[i].second] = 0;
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

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (board[ny][nx] != 1 && dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                if (board[ny][nx] == 0)
                {
                    infect += 1;
                    time = dist[ny][nx];
                }
                q.push(make_pair(ny, nx));
            }
        }
    }

    if (safe == infect)
        answer = min(answer, time);
}
void dfs(int index, int cnt)
{
    if (cnt == M)
    {
        activeVirus();
        return;
    }

    for (int i = index; i < virus.size(); i++)
    {
        selected[i] = true;
        dfs(i + 1, cnt + 1);
        selected[i] = false;
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
                safe += 1;
            else if (board[y][x] == 2)
                virus.push_back(make_pair(y, x));
        }
    }
    // 바이러스 선택
    // index, cnt
    dfs(0, 0);
    if (answer == INF)
        answer = -1;
    cout << answer << '\n';
    return 0;
}