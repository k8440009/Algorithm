// 뱀
// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100 + 1;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
struct HEAD
{
    int y, x, dir;
};
HEAD head;
int N, K, L;
int board[MAX][MAX];
vector<pair<int, char>> direction;
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
        y -= 1, x -= 1;
        board[y][x] = 1;
    }
    cin >> L;
    direction.resize(L);
    for (int i = 0; i < L; i++)
    {
        int time;
        char dir;
        cin >> time >> dir;
        direction[i].first = time, direction[i].second = dir;
    }

    board[0][0] = -1; //뱀
    head.y = 0, head.x = 0, head.dir = 1;
    queue<pair<int, int>> body;
    body.push(make_pair(0, 0));
    int time = 0, index = 0;

    while (true)
    {
        time += 1;

        int ny = head.y + dy[head.dir];
        int nx = head.x + dx[head.dir];

        // 종료
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == -1)
            break;

        // 다음칸 사과
        if (board[ny][nx] == 0)
        {
            board[body.front().first][body.front().second] = 0;
            body.pop();
        }
        body.push(make_pair(ny, nx));
        board[ny][nx] = -1;
        head.y = ny;
        head.x = nx;

        if (index < L)
        {

            if (time == direction[index].first)
            {
                if (direction[index].second == 'L')
                {
                    head.dir = (head.dir + 3) % 4;
                }
                else if (direction[index].second == 'D')
                {
                    head.dir = (head.dir + 1) % 4;
                }
                index += 1;
            }
        }
    }

    cout << time << '\n';
    return 0;
}
