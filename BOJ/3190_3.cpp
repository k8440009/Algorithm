// 뱀
// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct SNAKE
{
    int y, x, dir;
};
const int MAX = 100;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int N, K, L;
int board[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int y, x;
        cin >> y >> x;
        y -= 1;
        x -= 1;
        board[y][x] = 1;
    }
    cin >> L;
    vector<pair<int, char>> command(L);
    for (int i = 0; i < L; i++)
    {
        int t;
        char c;
        cin >> t >> c;
        command[i].first = t;
        command[i].second = c;
    }
    // 뱀
    SNAKE head;
    head.x = 0;
    head.y = 0;
    head.dir = 0;
    board[head.y][head.x] = -1;
    queue<pair<int, int>> tail;
    tail.push(make_pair(0, 0));

    int time = 0, index = 0;
    while (true)
    {
        time += 1;

        int ny = head.y + dy[head.dir];
        int nx = head.x + dx[head.dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == -1)
            break;

        if (board[ny][nx] == 0)
        {
            board[tail.front().first][tail.front().second] = 0;
            tail.pop();
        }

        board[ny][nx] = -1;
        tail.push(make_pair(ny, nx));
        head.y = ny;
        head.x = nx;

        if (command[index].first == time)
        {
            if (command[index].second == 'L')
                head.dir = (head.dir + 3) % 4;
            else
                head.dir = (head.dir + 1) % 4;
            index += 1;
        }
    }

    cout << time << '\n';
    return 0;
}