// 달팽이 숫자 D2
#include <iostream>
using namespace std;
int board[10][10];
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
        int N;
        cin >> N;

        int index = N * N;
        int y = 0, x = 0, num = 1;
        int sy = 0, ey = N - 1, sx = 0, ex = N - 1;
        int dir = 0; // 오른쪽, 아래,왼쪽,위
        while (index)
        {
            board[y][x] = num;
            switch (dir)
            {
                // 오른쪽
            case 0:
                if (x != ex)
                    x += 1;
                else
                {
                    sy += 1;
                    dir += 1;
                    y += 1;
                }
                break;
            // 아래
            case 1:
                if (y != ey)
                    y += 1;
                else
                {
                    ex -= 1;
                    dir += 1;
                    x -= 1;
                }
                break;
            // 왼쪽
            case 2:
                if (x != sx)
                    x -= 1;
                else
                {
                    ey -= 1;
                    dir += 1;
                    y -= 1;
                }
                break;
            // 위
            case 3:
                if (y != sy)
                    y -= 1;
                else
                {
                    sx += 1;
                    dir = 0;
                    x += 1;
                }
                break;
            }
            num += 1;
            index -= 1;
        }

        cout << "#" << ts << '\n';
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                cout << board[y][x] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}