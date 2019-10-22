// 사탕 게임
// https://www.acmicpc.net/problem/3085
/*
    참고
    https://jaimemin.tistory.com/1068
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 50;
int N, answer = 0;
char board[MAX][MAX];
int countCandy()
{
    int result = 1;
    // 양, 옆
    for (int y = 0; y < N; y++)
    {
        int temp = 1;
        for (int x = 1; x < N; x++)
        {
            if (board[y][x - 1] == board[y][x])
                temp++;
            else
            {
                result = max(result, temp);
                temp = 1;
            }
        }
        result = max(result, temp);
    }
    // 위, 아래
    for (int x = 0; x < N; x++)
    {
        int temp = 1;
        for (int y = 0; y < N - 1; y++)
        {
            if (board[y + 1][x] == board[y][x])
                temp++;
            else
            {
                result = max(result, temp);
                temp = 1;
            }
        }
        result = max(result, temp);
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
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            board[i][j] = str[j];
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N - 1; x++)
        {
            swap(board[y][x], board[y][x + 1]);
            answer = max(answer, countCandy());
            swap(board[y][x], board[y][x + 1]);

            swap(board[x][y], board[x + 1][y]);
            answer = max(answer, countCandy());
            swap(board[x][y], board[x + 1][y]);
        }
    }

    cout << answer << '\n';

    return 0;
}