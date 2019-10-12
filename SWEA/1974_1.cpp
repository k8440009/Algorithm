// 스도쿠 검증
#include <iostream>
#include <algorithm>
using namespace std;
int board[9][9];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        bool flag = true;
        for (int y = 0; y < 9; y++)
        {
            for (int x = 0; x < 9; x++)
            {
                cin >> board[y][x];
            }
        }
        // 가로
        for (int y = 0; y < 9; y++)
        {
            bool check[10];
            fill_n(check, 10, 0);
            for (int x = 0; x < 9; x++)
            {
                int num = board[y][x];
                if (check[num])
                {
                    flag = false;
                    break;
                }
                else
                    check[num] = true;
            }
        }
        // 세로
        for (int y = 0; y < 9; y++)
        {
            bool check[10];
            fill_n(check, 10, 0);
            for (int x = 0; x < 9; x++)
            {
                int num = board[x][y];
                if (check[num])
                {
                    flag = false;
                    break;
                }
                else
                    check[num] = true;
            }
        }
        // 네모칸
        for (int y = 0; y < 9; y += 3)
        {
            for (int x = 0; x < 9; x += 3)
            {
                bool check[10];
                fill_n(check, 10, 0);

                for (int r = 0; r < 3; r++)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        int num = board[r + y][c + x];
                        if (check[num])
                        {
                            flag = false;
                            break;
                        }
                        else
                            check[num] = true;
                    }
                }
            }
        }
        if (flag)
            cout << "#" << ts << ' ' << 1 << '\n';
        else
            cout << "#" << ts << ' ' << 0 << '\n';
    }
    return 0;
}