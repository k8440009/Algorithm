// 원판 돌리기
// https://www.acmicpc.net/problem/17822
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 50 + 1;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N, M, T;
bool flag = false;
int board[MAX][MAX];
void bfs(int y, int x, int num)
{
    bool visited[MAX][MAX];
    fill_n(visited[0], MAX * MAX, 0);
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    vector<pair<int, int>> target;
    target.push_back(make_pair(y, x));

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.second == 1)
        {
            if (!visited[cur.first][M] && board[cur.first][M] == num)
            {
                visited[cur.first][M] = true;
                q.push(make_pair(cur.first, M));
                target.push_back(make_pair(cur.first, M));
            }
        }
        else if (cur.second == M)
        {
            if (!visited[cur.first][1] && board[cur.first][1] == num)
            {
                visited[cur.first][1] = true;
                q.push(make_pair(cur.first, 1));
                target.push_back(make_pair(cur.first, 1));
            }
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 1 || ny >= N + 1 || nx < 1 || nx >= M + 1 || visited[ny][nx])
                continue;

            if (board[ny][nx] == num)
            {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                target.push_back(make_pair(ny, nx));
            }
        }
    }

    if (target.size() > 1)
    {
        flag = true;
        for (int i = 0; i < target.size(); i++)
            board[target[i].first][target[i].second] = 0;
    }
}
void rotate(int target, int direction, int count)
{
    // 회전
    for (int cnt = 1; cnt <= count; cnt++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (i % target == 0)
            {
                // 시계
                if (direction == 0)
                {
                    int temp = board[i][M];
                    for (int k = M; k - 1 >= 1; k--)
                    {
                        board[i][k] = board[i][k - 1];
                    }
                    board[i][1] = temp;
                }
                // 반시계
                else if (direction == 1)
                {
                    int temp = board[i][1];
                    for (int k = 1; k + 1 <= M; k++)
                    {
                        board[i][k] = board[i][k + 1];
                    }
                    board[i][M] = temp;
                }
            }
        }
    }

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= M; x++)
        {
            if (board[y][x] != 0)
                bfs(y, x, board[y][x]);
        }
    }
    // 삭제 안되면
    if (!flag)
    {
        int cnt = 0, total = 0;
        double avg = 0;
        vector<pair<int, int>> target;
        for (int y = 1; y <= N; y++)
        {
            for (int x = 1; x <= M; x++)
            {
                if (board[y][x] != 0)
                {
                    total += board[y][x];
                    cnt += 1;
                    target.push_back(make_pair(y, x));
                }
            }
        }

        avg = (double)total / (double)cnt;

        for (int i = 0; i < target.size(); i++)
        {
            int y = target[i].first, x = target[i].second;
            if (board[y][x] > avg)
                board[y][x] -= 1;
            else if (board[y][x] < avg)
                board[y][x] += 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> T;
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= M; x++)
            cin >> board[y][x];

    for (int i = 1; i <= T; i++)
    {
        flag = false;
        int x, d, k;
        cin >> x >> d >> k; // 배수,방향, 회전 횟수

        rotate(x, d, k);
    }

    int answer = 0;
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= M; x++)
            answer += board[y][x];

    cout << answer << '\n';

    return 0;
}