// 사탕 게임
// https://www.acmicpc.net/problem/3085
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 50;
int N, answer = 0;
char board[MAX][MAX];
int cntCandy()
{
    int result = 1;
    // 좌, 우
    for (int y = 0; y < N; y++)
    {
        int cnt = 1;
        for (int x = 0; x < N - 1; x++)
        {
            if (board[y][x] == board[y][x + 1])
                cnt += 1;
            else
            {
                result = max(result, cnt);
                cnt = 1;
            }
        }
        result = max(result, cnt);
    }

    // 위, 아래
    for (int x = 0; x < N; x++)
    {
        int cnt = 1;
        for (int y = 0; y < N - 1; y++)
        {
            if (board[y][x] == board[y + 1][x])
                cnt += 1;
            else
            {
                result = max(result, cnt);
                cnt = 1;
            }
        }
        result = max(result, cnt);
    }

    return result;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> board[i];

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N - 1; x++)
        {
            swap(board[y][x], board[y][x + 1]);
            answer = max(answer, cntCandy());
            swap(board[y][x], board[y][x + 1]);

            swap(board[x][y], board[x + 1][y]);
            answer = max(answer, cntCandy());
            swap(board[x][y], board[x + 1][y]);
        }
    }

    cout << answer << '\n';

    return 0;
}