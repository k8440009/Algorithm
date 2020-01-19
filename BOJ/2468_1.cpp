// 안전 영역
// https://www.acmicpc.net/problem/2468
/*
    1. 영역 입력 받는다.
    2. 1~최대 높이-1을 기준으로 물을 채운다.
    3. 그 다음, BFS OR DFS 탐색을 시행한다.
*/
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100 + 1;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int N, maxHeight = 0, minHeight = 101, answer = 1;
int board[MAX][MAX];
bool visited[MAX][MAX];
void bfs()
{
    int cnt = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            // 물에 잠기지 않고, 방문 하지 않은 섬
            if (board[y][x] != 0 && !visited[y][x])
            {
                cnt++;
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

                        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || board[ny][nx] == 0)
                            continue;

                        q.push(make_pair(ny, nx));
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }

    if (answer < cnt)
        answer = cnt;
}
void init()
{
    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    // 비가 정수만큼 내린 다는 말이 없으므로 1에서부터 MAX까지 계산한다.
    for (int i = 1; i <= 100; i++)
    {
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
                if (board[y][x] == i)
                    board[y][x] = 0;
        bfs();
        fill_n(visited[0], MAX * MAX, 0);
    }

    cout << answer << '\n';

    return 0;
}