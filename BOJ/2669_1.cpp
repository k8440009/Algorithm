// 직사각형 네개의 합집합의 면적 구하기
// https://www.acmicpc.net/problem/2669
#include <iostream>
using namespace std;
const int MAX = 100 + 1;
bool board[MAX][MAX];
int answer = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sx, sy, ex, ey;

    for (int ts = 1; ts <= 4; ts++)
    {
        cin >> sx >> sy >> ex >> ey;

        for (int y = sy; y < ey; y++)
        {
            for (int x = sx; x < ex; x++)
            {
                board[y][x] = true;
            }
        }
    }

    // 1 ~ 100
    for (int y = 1; y < MAX; y++)
    {
        for (int x = 1; x < MAX; x++)
        {
            if (board[y][x])
                answer += 1;
        }
    }

    cout << answer << '\n';
}