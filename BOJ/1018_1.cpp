// 체스판 다시 칠하기
// https://www.acmicpc.net/problem/1018
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 50;
int N, M;
char board[MAX][MAX];
int answer = 987654321;
void checkBoard(int sy, int sx)
{
    int cnt = 0;
    char start = board[sy][sx];

    for (int y = sy; y < sy + 8; y++)
    {
        for (int x = sx; x < sx + 8; x++)
        {
            // 두개가 같을 때
            if (y % 2 == x % 2)
            {
                if (board[y][x] != 'W')
                    cnt++;
            }
            else
            {
                if (board[y][x] != 'B')
                    cnt++;
            }
        }
    }
    answer = min(answer, min(64 - cnt, cnt)); // 회전
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];

    // 자르기 할 칸 선택
    for (int y = 0; y < M - 7; y++)
    {
        for (int x = 0; x < N - 7; x++)
        {
            checkBoard(y, x);
        }
    }

    cout << answer << '\n';
}