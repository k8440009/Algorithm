// 숫자고르기
// https://www.acmicpc.net/problem/2668
#include <iostream>
using namespace std;
const int MAX = 100 + 1;
int N;
int board[2][MAX];
void dfs(int index, int cnt)
{
    int next = board[1][index];
    dfs(next, cnt + 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        board[0][i] = i;
        cin >> board[1][i];
    }

    for (int i = 1; i <= N; i++)
    {
        dfs(i, 0);
    }

    return 0;
}