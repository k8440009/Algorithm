// 별 찍기 - 10
// https://www.acmicpc.net/problem/2447
#include <iostream>
using namespace std;
const int MAX = 2187;
int N;
char board[MAX][MAX];
void init()
{
    // 초기화
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            board[y][x] = ' ';
}
void divConq(int sy, int sx, int n)
{
    if (n == 1)
    {
        board[sy][sx] = '*';
        return;
    }

    int size = n / 3;

    divConq(sy, sx, size);
    divConq(sy, sx + size, size);
    divConq(sy, sx + size * 2, size);

    divConq(sy + size, sx, size);
    divConq(sy + size, sx + size * 2, size);

    divConq(sy + size * 2, sx, size);
    divConq(sy + size * 2, sx + size, size);
    divConq(sy + size * 2, sx + size * 2, size);

    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    init();

    divConq(0, 0, N);

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cout << board[y][x];
        }
        cout << '\n';
    }

    return 0;
}