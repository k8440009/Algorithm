// 연산자 끼워 넣기
// https://www.acmicpc.net/problem/14888
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 11 + 1;
const int INF = 987654321;
int board[MAX];
int N;
int command[4];
int Max = -INF;
int Min = INF;

void dfs(int index, int total, int plus, int minus, int mul, int div)
{
    if (index == N)
    {
        Max = max(Max, total);
        Min = min(Min, total);

        return;
    }
    if (plus > 0)
        dfs(index + 1, total + board[index], plus - 1, minus, mul, div);
    if (minus > 0)
        dfs(index + 1, total - board[index], plus, minus - 1, mul, div);
    if (mul > 0)
        dfs(index + 1, total * board[index], plus, minus, mul - 1, div);
    if (div > 0)
        dfs(index + 1, total / board[index], plus, minus, mul, div - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> board[i];
    for (int i = 0; i < 4; i++)
        cin >> command[i];

    dfs(1, board[0], command[0], command[1], command[2], command[3]);

    cout << Max << '\n';
    cout << Min << '\n';
    return 0;
}