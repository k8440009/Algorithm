// 사탕 게임
// https://www.acmicpc.net/problem/3085
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50 + 1;
char board[MAX][MAX];
int N;
int answer = 0;

int checkCandy(int y, int x)
{
    int result = 1;
    // 위, 아래
    int cnt = 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (board[y][i] == board[y][i + 1])
            cnt += 1;
        else
        {
            result = max(result, cnt);
            cnt = 1;
        }
        result = max(result, cnt);
    }
    cnt = 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (board[i][x] == board[i + 1][x])
            cnt += 1;
        else
        {
            result = max(result, cnt);
            cnt = 1;
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
    // 입력
    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];
    // 이동
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N - 1; x++)
        {
            swap(board[y][x], board[y][x + 1]);
            answer = max(answer, max(checkCandy(y, x), checkCandy(y, x + 1)));
            swap(board[y][x], board[y][x + 1]);

            swap(board[x][y], board[x + 1][y]);
            answer = max(answer, max(checkCandy(x, y), checkCandy(x + 1, y)));
            swap(board[x][y], board[x + 1][y]);
        }
    }
    cout << answer;
    return 0;
}