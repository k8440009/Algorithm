// 2105. [모의 SW 역량테스트] 디저트 카페
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20;
int N, answer;
int board[MAX][MAX];

void rect(int row, int col, int sy, int sx)
{
    int visit = 1;
    bool checkFood[101]; // 1 ~ 100
    fill_n(checkFood, 101, 0);
    checkFood[board[sy][sx]] = true;
    int y = sy;
    int x = sx;
    // 가로 -> 세로 -> 가로 ->세로
    // 1번 (y + 1, x + 1);
    for (int cnt = 1; cnt <= row; cnt++)
    {
        // 다음 방향
        int ny = y + 1;
        int nx = x + 1;

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            return;
        if (checkFood[board[ny][nx]])
            return;

        checkFood[board[ny][nx]] = true;
        y = ny;
        x = nx;
        visit += 1;
    }
    // 2번 (y + 1, x-1)
    for (int cnt = 1; cnt <= col; cnt++)
    {
        int ny = y + 1;
        int nx = x - 1;

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            return;
        if (checkFood[board[ny][nx]])
            return;

        checkFood[board[ny][nx]] = true;
        y = ny;
        x = nx;
        visit += 1;
    }
    // 3번 (y-1 x-1)
    for (int cnt = 1; cnt <= row; cnt++)
    {
        int ny = y - 1;
        int nx = x - 1;

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            return;
        if (checkFood[board[ny][nx]])
            return;

        checkFood[board[ny][nx]] = true;
        y = ny;
        x = nx;
        visit += 1;
    }
    // 4번 (y - 1, x + 1)
    for (int cnt = 1; cnt <= col; cnt++)
    {
        int ny = y - 1;
        int nx = x + 1;

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            return;
        // 시작점
        if (cnt == col)
        {
            // 시작점에 도달한 경우
            if (ny == sy && nx == sx)
            {
                answer = max(answer, visit);
            }
        }

        if (checkFood[board[ny][nx]])
            return;

        checkFood[board[ny][nx]] = true;
        y = ny;
        x = nx;
        visit += 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("sample_input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        answer = -1;
        cin >> N;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                cin >> board[y][x];
            }
        }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                // 가로
                for (int row = 1; row < N; row++)
                {
                    // 세로
                    for (int col = 1; col < N; col++)
                    {
                        rect(row, col, y, x);
                    }
                }
            }
        }

        cout << "#" << ts << ' ' << answer << '\n';
    }
    return 0;
}