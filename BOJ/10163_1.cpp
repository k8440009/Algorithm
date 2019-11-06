// 색종이
// https://www.acmicpc.net/problem/10163
#include <iostream>
using namespace std;
const int MAX = 100 + 1;
int N;
int board[MAX][MAX];
int paper[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    fill_n(board[0], MAX * MAX, -1);
    // 시작점, 가로, 세로
    for (int i = 0; i < N; i++)
    {
        int sy, sx, width, hegiht;
        cin >> sx >> sy >> width >> hegiht;

        for (int y = sy; y < sy + hegiht; y++)
        {
            for (int x = sx; x < sx + width; x++)
            {
                if (x >= MAX || y >= MAX)
                    continue;
                else
                    board[y][x] = i;
            }
        }
    }

    for (int y = 0; y < MAX; y++)
    {
        for (int x = 0; x < MAX; x++)
        {
            if (board[y][x] == -1)
                continue;
            else
                paper[board[y][x]]++;
        }
    }

    for (int i = 0; i < N; i++)
        cout << paper[i] << '\n';

    return 0;
}