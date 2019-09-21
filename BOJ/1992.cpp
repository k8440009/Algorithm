// 쿼드 트리
// https://www.acmicpc.net/problem/1992
#include <bits/stdc++.h>
using namespace std;

const int MAX = 64;
int N;
int board[MAX][MAX];

void recursive(int n, int y, int x)
{
    // 기저 사례
    if (n == 1)
    {
        cout << board[y][x];
        return;
    }
    bool zero = true, one = true;

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (board[i][j])
                zero = false;
            else
                one = false;
        }
    }

    if (zero)
        cout << 0;
    else if (one)
        cout << 1;
    else
    {
        cout << "(";
        recursive(n / 2, y, x);                 // 제 2 사분면
        recursive(n / 2, y, x + n / 2);         // 제 1 사분면
        recursive(n / 2, y + n / 2, x);         // 제 3 사분면
        recursive(n / 2, y + n / 2, x + n / 2); // 제 4 사분면
        cout << ")";
    }
    return;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    recursive(N, 0, 0);
    return 0;
}