// N-Queen
// https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;
const int MAX = 15 + 1;
int N, answer, row[MAX];
// 유망한지 아닌지 체크
bool promising(int q)
{
    // 전에 놓은 퀸 들에서 검사
    for (int i = 1; i < q; i++)
    {
        // 열이 같은 경우, 대각선이 같은 경우
        if (row[q] == row[i] || (abs(row[q] - row[i]) == abs(q - i)))
            return false;
    }
    return true;
}
// 퀸 놓음
void queens(int q)
{
    // 가지치기
    if (!promising(q))
        return;
    // 퀸 놓은 숫자가 N이랑 같은 경우
    if (q == N)
    {
        answer++;
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        // row[q + 1] : 행, i : 열
        row[q + 1] = i; // q+1 : 행, row[q+1] 열에 놓는다.
        queens(q + 1);  // 퀸의 갯수를 증가 시킨다.
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    queens(0);
    cout << answer;
    return 0;
}

/*
    갯수가 0일 때부터 시작하여,
*/