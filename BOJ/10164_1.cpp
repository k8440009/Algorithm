// 격자상의 경로
// https://www.acmicpc.net/problem/10164
#include <iostream>
using namespace std;
const int MAX = 15 + 1;
struct TARGET
{
    int y, x, num;
};
TARGET target;
int N, M, K;
int board[MAX][MAX];
int dp[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    int cnt = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            board[i][j] = cnt;
            if (board[i][j] == K)
                target.y = i, target.x = j, target.num = K;
            cnt += 1;
        }
    }

    dp[1][0] = 1;
    // 표시가 있을 때
    if (K > 0)
    {
        int ey = target.y, ex = target.x;
        for (int y = 1; y <= ey; y++)
        {
            for (int x = 1; x <= ex; x++)
            {
                dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]);
            }
        }

        int sy = target.y, sx = target.x;

        for (int y = sy; y <= N; y++)
        {
            for (int x = sx; x <= M; x++)
            {
                dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]);
            }
        }
    }
    else
    {
        for (int y = 1; y <= N; y++)
        {
            for (int x = 1; x <= M; x++)
            {
                dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]);
            }
        }
    }

    cout << dp[N][M] << '\n';
}