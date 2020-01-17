// 게임
// https://www.acmicpc.net/problem/1103
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 50 + 1;
const int INF = 98765431;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int N, M, answer = INF;
int board[MAX][MAX];
int cache[MAX][MAX];
bool visited[MAX][MAX];
bool inRange(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}
int dfs(int y, int x)
{
    if (visited[y][x])
        return INF;
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    visited[y][x] = true;
    ret = 1;
    int temp, ny, nx;
    for (int dir = 0; dir < 4; dir++)
    {
        int move = board[y][x];
        ny = y + dy[dir] * move;
        nx = x + dx[dir] * move;

        if (inRange(ny, nx) && board[ny][nx])
        {
            temp = dfs(ny, nx);
            if (temp == INF)
                return INF;
            ret = max(ret, temp + 1);
        }
    }
    visited[y][x] = false;
    return ret;
}

void init()
{
    cin >> N >> M;
    fill_n(cache[0], MAX * MAX, -1);
    for (int y = 0; y < N; y++)
    {
        string s;
        cin >> s;
        for (int x = 0; x < M; x++)
        {
            if (s[x] == 'H')
                board[y][x] = 0;
            else
                board[y][x] = s[x] - '0';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int result = dfs(0, 0);
    if (result == INF)
        result = -1;
    cout << result;
    return 0;
}

/*
	참조
	https://github.com/kks227/BOJ/blob/master/1100/1103.cpp
	https://j2wooooo.tistory.com/83
	https://lcs11244.tistory.com/63
	https://vjerksen.tistory.com/78
*/