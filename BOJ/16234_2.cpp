// 인구이동
// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct NODE
{
    int y, x;
};
const int MAX = 50;
int N, L, R;
int board[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
        }
    }

    int change = 0;
    bool isUpdate = true;
    while (isUpdate)
    {
        isUpdate = false;
        bool visited[MAX][MAX];

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                int total = board[y][x];
                vector<pair<int, int>> alias;
                alias.push_back(make_pair(y, x));
                queue<pair<int, int>> q;
                q.push(make_pair(y, x));
                visited[y][x] = true;

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];

                        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
                            continue;

                        if (abs(board[ny][nx] - board[cur.first][cur.second]) >= L && abs(board[ny][nx] - board[cur.first][cur.second]) <= R)
                        {
                            alias.push_back(make_pair(ny, nx));
                            q.push(make_pair(ny, nx));
                            visited[ny][nx] = true;
                            total += board[ny][nx];
                        }
                    }
                }

                if (alias.size() == 1)
                    continue;
                else
                {
                    int people = total / alias.size();
                    for (int i = 0; i < alias.size(); i++)
                    {
                        board[alias[i].first][alias[i].second] = people;
                    }
                    isUpdate = true;
                    change += 1;
                    fill_n(visited[0], MAX * MAX, 0);
                }
            }
        }
    }

    cout << change << '\n';
    return 0;
}