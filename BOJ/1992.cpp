// 쿼드 트리
// https://www.acmicpc.net/problem/1992
#include <bits/stdc++.h>
using namespace std;

const int MAX = 64;
int N;
int board[MAX][MAX];

void recursive(int x, int y, int size)
{
    int half = size / 2;
    recursive(x + half, y, half);
    recursive(x, y + half, half);
    recursive(x + half, y + half, half);
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

    recursive(0, 0, N);
    return 0;
}