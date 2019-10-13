// 1209 Sum
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100;
int board[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    int temp = 10;
    while (temp--)
    {
        int tc;
        cin >> tc;
        for (int y = 0; y < 100; y++)
        {
            for (int x = 0; x < 100; x++)
            {
                cin >> board[y][x];
            }
        }

        int answer = 0;
        int left = 0;
        int right = 0;
        for (int y = 0; y < 100; y++)
        {
            int row = 0;
            int col = 0;
            for (int x = 0; x < 100; x++)
            {
                row += board[y][x];
                col += board[x][y];
                // 왼쪽 대각선
                if (y == x)
                    left += board[y][x];
            }

            right += board[y][99 - y];
            answer = max(answer, row);
            answer = max(answer, col);
        }
        answer = max(answer, right);
        answer = max(answer, left);

        cout << "#" << tc << ' ' << answer << '\n';
    }

    return 0;
}