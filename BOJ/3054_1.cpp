// 피터팬 프레임
// https://www.acmicpc.net/problem/3054
#include <iostream>
#include <string>
using namespace std;
const int MAX = 15 + 1;
int sy = 0, sx = 0;
char board[5][5 * MAX];
void wendy(int sx, char eng)
{
    board[0][sx + 2] = '*';
    board[1][sx + 1] = '*';
    board[1][sx + 3] = '*';
    board[2][sx] = '*';
    board[2][sx + 2] = eng;
    board[2][sx + 4] = '*';
    board[3][sx + 1] = '*';
    board[3][sx + 3] = '*';
    board[4][sx + 2] = '*';
}
void piter(int sx, char eng)
{
    board[0][sx + 2] = '#';
    board[1][sx + 1] = '#';
    board[1][sx + 3] = '#';
    board[2][sx] = '#';
    board[2][sx + 2] = eng;
    board[2][sx + 4] = '#';
    board[3][sx + 1] = '#';
    board[3][sx + 3] = '#';
    board[4][sx + 2] = '#';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    for (int y = 0; y < 5; y++)
        for (int x = 0; x < str.size() * 5; x++)
            board[y][x] = '.';

    int j = 0;
    // 1. 피터팬 프레임 칠 한 후, 웬디 프레임 덮어 씌운다.
    for (int i = 1; i <= str.size(); i++)
    {
        piter(j, str[i - 1]);
        j += 4;
    }
    j = 0;
    for (int i = 1; i <= str.size(); i++)
    {
        if (i % 3 == 0)
            wendy(j, str[i - 1]);
        j += 4;
    }

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < str.size() * 5 - (str.size() - 1); x++)
        {
            cout << board[y][x];
        }
        cout << '\n';
    }

    return 0;
}