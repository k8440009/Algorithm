// N-Queen
// https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;
const int MAX = 15 + 1;
bool board[MAX][MAX];
int N, Row[100]; // Row[1] = 2, 1번행 2열

void printResult()
{
    static int cnt = 1;
    cout << cnt++ << '\n';
    for (int i = 1; i <= N; i++)
    {
        cout << "(" << i << ' ' << Row[i] << ")" << ' '; // 행, 열
    }
    cout << '\n';
}
// 유망한지 안하는지 체크
bool promising(int q)
{
    for (int i = 1; i < q; i++)
    {
        // 각 행에 q 하나만 놓기로 하였으므로 행은 검사 할 필요가 없다.
        if (Row[q] == Row[i]) // 열이 같은 경우
            return false;
        else if (abs(Row[q] - Row[i]) == abs(q - i)) // dy == dx가 같은 경우 (대각선)
            return false;
    }
    return true;
}
void queens(int q)
{
    if (!promising(q))
        return;
    if (q == N)
    {
        printResult();
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        Row[q + 1] = i;
        queens(q + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    queens(0);
    return 0;
}
/*
    참고
    SWEA Advanced 강의
*/