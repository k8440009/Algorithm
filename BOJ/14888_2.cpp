// 연산자 끼워 넣기
// https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 11;
const int INF = 987654321;
int N;
int num[MAX];
int command[4];
int Min = INF;
int Max = -INF;
void dfs(int index, int total, int plus, int minus, int mul, int div)
{
    if (index == N)
    {
        Min = min(Min, total);
        Max = max(Max, total);
        return;
    }

    if (plus > 0)
        dfs(index + 1, total + num[index], plus - 1, minus, mul, div);
    if (minus > 0)
        dfs(index + 1, total - num[index], plus, minus - 1, mul, div);
    if (mul > 0)
        dfs(index + 1, total * num[index], plus, minus, mul - 1, div);
    if (div > 0)
        dfs(index + 1, total / num[index], plus, minus, mul, div - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> command[i];

    // cnt total, 덧셈, 뺼셈, 곱셈, 나눗셈
    dfs(1, num[0], command[0], command[1], command[2], command[3]);

    cout << Max << '\n';
    cout << Min << '\n';
    return 0;
}