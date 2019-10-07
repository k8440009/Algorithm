// 경사로
// https://www.acmicpc.net/problem/14890
#include <iostream>
using namespace std;
const int MAX = 100;
int N, L, answer;
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
            board[y + N][x] = board[x][y];
    }

    int cnt;
    int i, j;
    answer = 0;
    for (i = 0; i < 2 * N; i++)
    {
        cnt = 1;
        for (j = 0; j < N - 1; j++)
        {
            // 평지
            if (board[i][j] == board[i][j + 1])
            {
                cnt += 1;
            }
            // 오르막
            else if (board[i][j] + 1 == board[i][j + 1] && cnt >= L)
            {
                cnt = 1;
            }
            // 내리막
            else if (board[i][j] - 1 == board[i][j + 1] && cnt >= 0)
            {
                cnt = (1 - L);
            }
            else
                break;
        }
        if (j == (N - 1) && cnt >= 0)
            answer += 1;
    }

    cout << answer << '\n';
    return 0;
}