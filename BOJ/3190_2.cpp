// 뱀
// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
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

    int time = 0, index = 0;
    pair<int, int> head;
    head.first = 0;
    head.second = 0;
    board[0][0] = -1;
    int dir = 0;
    queue<pair<int, int>> tail;
    tail.push(make_pair(0, 0));

    while (true)
    {
        time += 1;

        int ny = head.first + dy[dir];
        int nx = head.second + dx[dir];
        // 종료
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == -1)
            break;
        // 사과 없는 경우
        if (board[ny][nx] == 0)
        {
            board[tail.front().first][tail.front().second] = 0;
            tail.pop();
        }
        board[ny][nx] = -1;
        tail.push(make_pair(ny, nx));
        head.first = ny;
        head.second = nx;

        if (command[index].first == time)
        {
            if (command[index].second == 'L')
                dir = (dir + 3) % 4;
            else if (command[index].second == 'D')
                dir = (dir + 1) % 4;
            index += 1;
        }
    }

    cout << time << '\n';

    return 0;
}