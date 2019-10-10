// 배열 돌리기 4
// https://www.acmicpc.net/problem/17406
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
int N, M, K;
int board[MAX][MAX];
int nextBoard[MAX][MAX];
void rotateBoard(int r, int c, int s)
{
    for (int y = r - s - 1; y < r + s; y++)
    {
        for (int x = r - c - 1; x < c + s; x++)
        {
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        int r, c, s;
        cin >> r >> c >> s;
        rotateBoard(r, c, s);
    }
    return 0;
}