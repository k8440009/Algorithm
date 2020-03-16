// 연구소 3
// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50 + 1;
const int INF = 987654321;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N, M, answer, safe;
int board[MAX][MAX];
bool selected[11];
vector<pair<int, int>> virus;
void bfs()
{

    int dist[MAX][MAX];
    int infect = 0, time = 0;
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

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 1)
                continue;

            if (board[ny][nx] != 1 && dist[ny][nx] == -1)
            {
                q.push(make_pair(ny, nx));
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                if (board[ny][nx] == 0)
                {
                    infect += 1;
                    time = dist[ny][nx];
                }
            }
        }
    }

    if (infect == safe)
    {
        answer = min(answer, time);
    }
}
// 바이러스 M개 선택
void dfs(int index, int cnt)
{
    if (cnt == M)
    {
        bfs();
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

    // 바이러스 크기, 활성화 바이러스
    cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == 0)
            {
                safe += 1;
            }
            else if (board[y][x] == 2)
            {
                virus.push_back(make_pair(y, x));
            }
        }
    }

    answer = INF;
    // index, cnt
    dfs(0, 0);
    if (answer == INF)
        answer = -1;
    cout << answer << '\n';
    return 0;
}