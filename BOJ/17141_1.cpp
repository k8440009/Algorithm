// 연구소 2
// https://www.acmicpc.net/problem/17141
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 50;
const int INF = 987654321;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N, M, answer = INF;

int board[MAX][MAX];
int practice[MAX][MAX];
vector<pair<int, int>> virus;
bool selected[10];
void activeVirus()
{
    int time = 0, infect = 0, blank = 0;
    int dist[MAX][MAX];
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            practice[y][x] = board[y][x];
            dist[y][x] = -1;
            if (board[y][x] == 0)
                blank += 1;
            else if (board[y][x] == 2)
            {
                practice[y][x] = 0;
                blank += 1;
            }
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < virus.size(); i++)
    {
        if (selected[i])
        {
            int y = virus[i].first;
            int x = virus[i].second;
            q.push(make_pair(y, x));
            practice[y][x] = 2;
            dist[y][x] = 0;
            blank -= 1;
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        int y = cur.first;
        int x = cur.second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            // 방문하지 않았고, 벽이 아닌 경우
            if (practice[ny][nx] != 1 && dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[y][x] + 1;

                if (practice[ny][nx] == 0)
                {
                    time = dist[ny][nx];
                    infect += 1;
                }

                q.push(make_pair(ny, nx));
            }
        }
    }

    if (infect == blank)
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
            if (board[y][x] == 2)
            {
                virus.push_back(make_pair(y, x));
            }
        }
    }
    // cnt, y,x
    dfs(0, 0);
    if (answer == INF)
        answer = -1;
    cout << answer << '\n';
    return 0;
}
