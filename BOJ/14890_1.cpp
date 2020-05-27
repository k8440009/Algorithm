// 경사로 1회차
// https://www.acmicpc.net/problem/14890
#include <iostream>
using namespace std;
const int MAX = 100;
int N, L; // 배열 길이, 경사로 길이
int board[MAX * 2][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
            cin >> board[y][x];
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            board[N + y][x] = board[x][y];
        }
    }

    int answer = 0;

    for (int y = 0; y < 2 * N; y++)
    {
        int size = L;
        int cnt = 1;
        int height = board[y][0];
        bool check = true;

        for (int x = 1; x < N; x++)
        {
            if (board[y][x] == height)
            {
                cnt += 1;
                continue;
            }
            // 기존의 높이보다 클 때
            else if (board[y][x] == height + 1)
            {
                if (cnt >= L)
                {
                    cnt = 1;
                    height = board[y][x];
                    continue;
                }
                else
                {
                    check = false;
                    break;
                }
            }
            // 작을 때
            else if (board[y][x] == height - 1)
            {
                int start = x;
                bool temp = true;
                // N의 범위를 초과하지 않을 때
                if (x + L - 1 < N)
                {
                    // 경사로 체크
                    while (start < x + L)
                    {
                        if (board[y][start] != height - 1)
                        {
                            temp = false;
                            break;
                        }
                        start += 1;
                    }
                }
                else
                {
                    check = false;
                    break;
                }

                if (temp)
                {
                    x += L - 1;
                    height = board[y][x];
                    cnt = 0;
                    continue;
                }
                else
                {
                    check = false;
                }
            }

            else
            {
                check = false;
                break;
            }
        }

        if (check)
            answer += 1;
    }

    cout << answer << '\n';

    return 0;
}
