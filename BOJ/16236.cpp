// 아기 상어
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 20;
int n;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dist;

struct st
{
    int x, y;
    int size = 2; // 아기 상어 크기
    int eat = 0;  // 먹은 양
};

st shark;

void init()
{
    minX;
    minY;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            visited[i][j] = -1;
        }
    }
}

void bfs()
{
    queue<pair<int, int>> q;
    visited[shark.x][shark.y] = true;
    q.push({shark.x, shark.y});

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = now.first + dx[dir];
            int ny = now.second + dy[dir];
            // 지도 밖으로 나간 경우
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            // 이미 방문 한 경우
            if (visited[nx][ny])
                continue;
            // 상어의 크기보다 큰 물고기 인경우
            if (board[nx][ny] > shark.size)
                continue;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                shark.x = i;
                shark.y = j;
                board[i][j] = 0;
            }
        }
    }

    // bfs
    return 0;
}