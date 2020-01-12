// N-Queen
// https://www.acmicpc.net/problem/9663
#include <bits/stdc++.h>
using namespace std;
const int MAX = 15;
bool visited[MAX][MAX];
bool checkColumn[MAX];
bool checkLeftDig[MAX * 3];  // 왼쪽 대각선
bool checkRightDig[MAX * 3]; // 오른쪽 대각선
int N;
int answer;
bool check(int row, int col)
{
    if (checkColumn[col])
        return false;
    if (checkLeftDig[row + col])
        return false;
    if (checkRightDig[row - col + N])
        return false;
    return true;
}
int dfs(int row)
{
    if (row == N)
    {
        return 1;
    }

    int cnt = 0;
    for (int col = 0; col < N; col++)
    {
        if (check(row, col))
        {
            checkLeftDig[row + col] = true;
            checkRightDig[row - col + N] = true;
            checkColumn[col] = true;
            visited[row][col] = true;
            cnt += dfs(row + 1);
            checkLeftDig[row + col] = false;
            checkRightDig[row - col + N] = false;
            checkColumn[col] = false;
            visited[row][col] = false;
        }
    }

    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    cout << dfs(0) << '\n';
    return 0;
}