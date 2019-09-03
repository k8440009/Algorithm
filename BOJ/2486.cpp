// 안전 영역
// https: //www.acmicpc.net/problem/2468
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100;
int n;
int height = 0;
int answer = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny] || temp[nx][ny] == 0)
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return;
}
void copyBoard(int rain)
{
    fill_n(visited[0], MAX * MAX, 0);
    fill_n(temp[0], MAX * MAX, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = board[i][j];
            if (temp[i][j] <= rain)
            {
                temp[i][j] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (height < board[i][j])
                height = board[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        copyBoard(i);
        int safe = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 잠수되지 않고, 방문하지 않은 지역인 경우
                if (temp[i][j] > 0 && !visited[i][j])
                {
                    bfs(i, j);
                    safe++;
                }
            }
        }

        answer = max(answer, safe);
    }

    cout << answer << '\n';
}