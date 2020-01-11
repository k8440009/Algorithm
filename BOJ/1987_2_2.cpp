// 알파벳
// https://www.acmicpc.net/problem/1987
#include <iostream>
using namespace std;
const int MAX = 20 + 1;
const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};
int R, C, answer;
char board[MAX][MAX];
bool alpha[26];
void dfs(int r, int c, int visitedSet, int cnt)
{
    if (cnt > answer)
        answer = cnt;

    for (int dir = 0; dir < 4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;

        int next = 1 << (int)(board[nr][nc] - 'A');
        if ((visitedSet & next) == 0)
            dfs(nr, nc, visitedSet | next, cnt + 1);
    }
}
void init()
{
    cin >> R >> C;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> board[r][c];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int next = board[0][0] - 'A';
    dfs(0, 0, 1 << next, 1);
    cout << answer << '\n';
    return 0;
}

/*
    방문한 알파벳만을 체크하며 퇴각검색을 하여도 풀 수 있긴 하지만 연습 삼아 비트마스크를 추가하였다.
    속도 차이는 없다.
*/