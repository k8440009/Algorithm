// 로봇 청소기
// https://www.acmicpc.net/problem/4991
#include <bits/stdc++.h>
using namespace std;
/*
    1. bfs
    2. dfs
*/
int n, m;

const int MAX = 20;
char board[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> m >> n;
        int dust = 0;
        int startX, startY, lastX, lastY;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'o')
                {
                    startX = i;
                    startY = j;
                    visited[i][j] = 0;
                }
                else if (board[i][j] == '*')
                {
                                }
            }
        }
    }
}