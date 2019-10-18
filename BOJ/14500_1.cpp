// 테트로미노
// https://www.acmicpc.net/problem/14500
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500 + 3;
int N, M;
int board[MAX][MAX];
const char block[19][4][5] = {
    {
        "1111",
        "0000",
        "0000",
        "0000",
    },
    {
        "1000",
        "1000",
        "1000",
        "1000",
    },
    {
        "1100",
        "1100",
        "0000",
        "0000",
    },
    {
        "1000",
        "1000",
        "1100",
        "0000",
    },
    {
        "1110",
        "1000",
        "0000",
        "0000",
    },
    {
        "1100",
        "0100",
        "0100",
        "0000",
    },
    {
        "0010",
        "1110",
        "0000",
        "0000",
    },
    {
        "0100",
        "0100",
        "1100",
        "0000",
    },
    {
        "1000",
        "1110",
        "0000",
        "0000",
    },
    {
        "1100",
        "1000",
        "1000",
        "0000",
    },
    {
        "1110",
        "0010",
        "0000",
        "0000",
    },
    {
        "1000",
        "1100",
        "0100",
        "0000",
    },
    {
        "0110",
        "1100",
        "0000",
        "0000",
    },
    {
        "0100",
        "1100",
        "1000",
        "0000",
    },
    {
        "1100",
        "0110",
        "0000",
        "0000",
    },
    {
        "1110",
        "0100",
        "0000",
        "0000",
    },
    {
        "0100",
        "1100",
        "0100",
        "0000",
    },
    {
        "0100",
        "1110",
        "0000",
        "0000",
    },
    {
        "1000",
        "1100",
        "1000",
        "0000",
    }};
int getCount(int sy, int sx, int k)
{
    int ret = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            ret += (block[k][y][x] - '0') * board[sy + y][sx + x];
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
        }
    }

    for (int y = N; y < N + 3; y++)
    {
        for (int x = 0; x < M + 3; x++)
        {
            board[y][x] = -100000;
        }
    }

    for (int y = 0; y < N + 3; y++)
    {
        for (int x = M; x < M + 3; x++)
        {
            board[y][x] = -100000;
        }
    }

    int answer = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            for (int k = 0; k < 19; k++)
            {
                int candi = getCount(y, x, k);
                answer = max(answer, candi);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}