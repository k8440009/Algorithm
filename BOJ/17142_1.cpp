// 연구소 3
// https://www.acmicpc.net/problem/17142
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int INF = 987654321;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int N, M, answer, blank;
int board[MAX][MAX];
vector<pair<int, int>> virus;
bool selected[10];
void activeVirus()
{
    int dist[MAX][MAX];
    fill_n(dist[0], MAX * MAX, -1);

    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++)
    {
        if (selected[i])
        {
            int y = virus[i].first;
            int x = virus[i].second;
            q.push(make_pair(y, x));
            dist[y][x] = 0;
        }
    }

    int time = 0, infect = 0;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (board[ny][nx] != 1 && dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[y][x] + 1;
                if (board[ny][nx] == 0)
                {
                    infect += 1;
                    time = dist[ny][nx];
                }
                q.push(make_pair(ny, nx));
            }
        }
    }

    if (infect == blank && answer > time)
        answer = time;

    return;
}
void setVirus(int index, int cnt)
{
    if (cnt == M)
    {
        /*
        for (int i = 0; i < virus.size(); i++)
        {
            if (selected[i])
                cout << i << ' ';
        }
        cout << '\n';
        */
        activeVirus();
        return;
    }

    for (int i = index; i < virus.size(); i++)
    {
        selected[i] = true;
        setVirus(i + 1, cnt + 1);
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
                virus.push_back(make_pair(y, x));
            else if (board[y][x] == 0)
                blank += 1;
        }
    }

    answer = INF;
    setVirus(0, 0);
    if (answer == INF)
        answer = -1;
    cout << answer << '\n';

    return 0;
}