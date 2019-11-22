// 마술사 이민혁
// https://www.acmicpc.net/problem/3023
#include <iostream>
using namespace std;
const int MAX = 100 + 1;
char board[MAX][MAX];
int r, c;
void right(int sr, int sc)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            board[i][(2 * c - 1) - j] = board[i][j];
        }
    }
}
void down(int sr, int sc)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            board[(2 * r - 1) - i][j] = board[i][j];
        }
    }
}
void dig(int sr, int sc)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            board[(2 * r - 1) - i][(2 * c - 1) - j] = board[i][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> board[i][j];

    int sr = 0, sc = 0;
    right(sr, sc + c);
    down(sr + r, sc);
    dig(sr + r, sc + c);

    int er, ec;
    cin >> er >> ec;
    if (board[er - 1][ec - 1] == '.')
        board[er - 1][ec - 1] = '#';
    else
        board[er - 1][ec - 1] = '.';

    for (int i = 0; i < r * 2; i++)
    {
        for (int j = 0; j < c * 2; j++)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}