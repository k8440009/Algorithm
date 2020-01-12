// 스도쿠
// https://www.acmicpc.net/problem/2580
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> zero;
int board[9][9];
bool promising(int r, int c, int target)
{
    // 가로, 세로
    for (int temp = 0; temp < 9; temp++)
    {
        if (board[temp][c] == target || board[r][temp] == target)
            return false;
    }
    // 3*3
    int sr = (r / 3) * 3, sc = (c / 3) * 3;
    for (int y = sr; y < sr + 3; y++)
        for (int x = sc; x < sc + 3; x++)
            if (board[y][x] == target)
                return false;
    return true;
}
// 찾은 갯수, zero의 위치
void sudoku(int cnt, int r, int c)
{
    // 기저
    if (cnt == zero.size() - 1)
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
                cout << board[r][c] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    for (int num = 1; num <= 9; num++)
    {
        // 가지치기
        if (promising(r, c, num))
        {
            board[r][c] = num;
            sudoku(cnt + 1, zero[cnt + 1].first, zero[cnt + 1].second);
            board[r][c] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
        {
            cin >> board[r][c];
            if (board[r][c] == 0)
                zero.push_back(make_pair(r, c));
        }
    zero.push_back(make_pair(-1, -1)); // 마지막

    // 찾은 갯수, zeroR, zeroC
    sudoku(0, zero[0].first, zero[0].second);
}
/*
    숫자 선택
    1. 적절한지 확인
    1_1) 적절하면 표시하고 , dfs
    1_2) 아니면 숫자 증가
    2. dfs 탈출하면
    숫자 돌려 놓음
*/