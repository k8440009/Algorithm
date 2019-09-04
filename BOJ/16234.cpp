// 인구이동
// https://www.acmicpc.net/problem/16234
#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
int n, l, r;

int board[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 0;
int change = 0;
bool check = true;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> position;

    while (check)
    {
        ++change;
        answer += 1;
        check = false; // 연합 체크
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == change)
                    continue;
                int sum = board[i][j];
                q.push({j, i});
                position.push({j, i});
                visited[i][j] = change;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        // 범위 초과
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        // 이번 변화에서 벗어난 경우
                        if (visited[ny][nx] == change)
                            continue;
                        // 차이에서 벗어나는 경우
                        if (abs(board[y][x] - board[ny][nx]) < l || abs(board[y][x] - board[ny][nx]) > r)
                            continue;

                        check = true; // 연합이 존재 하므로  true
                        q.push({nx, ny});
                        position.push({nx, ny});
                        sum += board[ny][nx];
                        visited[ny][nx] = change;
                    }
                }

                int avg = sum / position.size();

                while (!position.empty())
                {
                    board[position.front().second][position.front().first] = avg;
                    position.pop();
                }
            }
        }
    }
    cout << answer - 1 << '\n';
    return 0;
}