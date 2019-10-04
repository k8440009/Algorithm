// 행렬 곱셈
// https://www.acmicpc.net/problem/2740
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int N, M, K;
int board[3][MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[0][i][j];

    cin >> M >> K;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> board[1][i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < M; k++)
                board[2][i][j] += (board[0][i][k] * board[1][k][j]);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
            cout << board[2][i][j] << ' ';
        cout << '\n';
    }

    return 0;
}