// 인구이동
// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int N, L, R;
int board[MAX][MAX];

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

    int answer = 0;
    bool isUpdate = true;
    while (isUpdate)
    {
        isUpdate = false;

        bool visited[MAX][MAX];
        fill_n(visited[0], MAX * MAX, 0);

        vector<pair<int, int>> alias;
        queue<pair<int, int>> q;

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (visited[y][x])
                    continue;

                int total = 0;

                q.push(make_pair(y, x));
                alias.push_back(make_pair(y, x));
                visited[y][x] = true;
                total += board[y][x];

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

                        int dist = abs(board[ny][nx] - board[cur.first][cur.second]);
                        if (dist >= L && dist <= R)
                        {
                            alias.push_back(make_pair(ny, nx));
                            q.push(make_pair(ny, nx));
                            visited[ny][nx] = true;
                            total += board[ny][nx];
                            isUpdate = true;
                        }
                    }
                }

                if (alias.size() == 1)
                {
                    alias.clear();
                    continue;
                }
                else
                {
                    int people = total / alias.size();
                    for (int i = 0; i < alias.size(); i++)
                    {
                        board[alias[i].first][alias[i].second] = people;
                    }
                    alias.clear();
                }
            }
        }

        answer += 1;
    }

    cout << answer - 1 << '\n';
    return 0;
}
