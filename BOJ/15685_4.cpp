// 드래곤 커브
// https://www.acmicpc.net/problem/15685
#include <iostream>
using namespace std;

const int MAX = 101;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

int N;
int board[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        // x,y,방향, 세대
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        int curve[1024];
        int size = 0;
        curve[size] = d;
        size += 1;
        board[y][x] = 1;
        /*
            0 : 0
            1 : 0 1
            2 : 0 1 2 1
        */
        // 방향 계산
        for (int j = 0; j < g; j++)
        {
            for (int k = size - 1; k >= 0; k--)
            {
                curve[size] = (curve[k] + 1) % 4;
                size += 1;
            }
        }

        for (int j = 0; j < size; j++)
        {
            y += dy[curve[j]];
            x += dx[curve[j]];

            if (y < 0 || y >= MAX || x < 0 || x >= MAX)
                continue;

            board[y][x] = 1;
        }
    }

    for (int y = 0; y < MAX - 1; y++)
    {
        for (int x = 0; x < MAX - 1; x++)
        {
            if (board[y][x] && board[y + 1][x] && board[y][x + 1] && board[y + 1][x + 1])
                answer += 1;
        }
    }

    cout << answer << '\n';

    return 0;
}