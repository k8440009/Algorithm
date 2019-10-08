// 캐슬 디펜스
// https://www.acmicpc.net/problem/17135
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 15;
int N, M, D, answer;
int enemy;
int board[MAX][MAX];
bool selected[MAX];
void active()
{
    // 공격
    for (int i = 0; i < M; i++)
    {
    }
    // 적 이동
}
void dfs(int index, int cnt)
{
    if (cnt == 3)
    {
        // 2. 궁수 3명 선택 후, 실행
        active();
        return;
    }

    for (int i = index; i < M; i++)
    {
        selected[i] = true;
        dfs(index + 1, cnt + 1);
        selected[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                enemy += 1;
        }
    }

    answer = 0;
    // 1. 궁수 선택
    dfs(0, 0);

    return 0;
}