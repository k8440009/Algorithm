// 드래곤 커브
// https://www.acmicpc.net/problem/15685
#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
int board[MAX][MAX];
int N;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y, d, g;
        int curve[1024];
        fill_n(curve, 1024, 0);
        int size = 0;
        // x,y, 시작, 세대
        cin >> x >> y >> d >> g;

        curve[size++] = d;
        board[y][x] = 1;

        for (int j = 0; j < g; j++)
        {
            for (int k = size - 1; k >= 0; k--)
            {
                curve[size++] = (curve[k] + 1) % 4;
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

    int answer = 0;
    for (int y = 0; y < MAX - 1; y++)
    {
        for (int x = 0; x < MAX - 1; x++)
        {
            if (board[y][x] && board[y + 1][x] && board[y][x + 1] && board[y + 1][x + 1])
            {
                answer += 1;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}