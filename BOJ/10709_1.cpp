// 기상캐스터
// https://www.acmicpc.net/problem/10709
#include <iostream>
using namespace std;
const int MAX = 100 + 1;
int H, W;
char cloud[MAX][MAX];
int board[MAX][MAX];
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    fill_n(board[0], MAX * MAX, -1);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> cloud[i][j];

    for (int y = 0; y < H; y++)
    {
        int now = 0;
        bool flag = false;
        for (int x = 0; x < W; x++)
        {
            // 구름 만남
            if (cloud[y][x] == 'c')
            {
                flag = true;
                now = 0;
                board[y][x] = now;
            }
            else if (flag && cloud[y][x] == '.')
            {
                // 지나온 길에 구름이 있는 경우
                now += 1;
                board[y][x] = now;
            }

            cout << board[y][x] << ' ';
        }
        cout << '\n';
    }

    return 0;
}