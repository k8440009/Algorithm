// 사다리 조작
// https://www.acmicpc.net/problem/15684
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, H, answer;
int board[31][11];
bool check()
{
    bool ret = true;

    for (int i = 1; i <= N; i++)
    {
        int position = i;

        for (int j = 1; j <= H; j++)
        {
            if (board[j][position] == 1)
                position++;
            else if (board[j][position - 1] == 1)
                position--;
        }

        if (position != i)
        {
            return ret = false;
        }
    }

    return ret;
}
void dfs(int count, int y, int x)
{
    if (count >= answer)
        return;
    if (check())
    {
        answer = count;
        return;
    }
    if (count == 3)
        return;

    for (int i = y; i <= H; i++)
    {
        for (int j = x; j < N; j++)
        {
            if (board[i][j] == 0 && board[i][j - 1] == 0 && board[i][j + 1] == 0)
            {
                board[i][j] = 1;
                dfs(count + 1, i, j);
                board[i][j] = 0;
            }
        }

        x = 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> N >> M >> H; // 세로선 갯수, 가로선 갯수
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        board[a][b] = 1;
    }

    answer = 4;
    dfs(0, 1, 1);
    if (answer == 4)
        answer = -1;
    cout << answer << '\n';
    return 0;
}