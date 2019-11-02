// 색종이
// https://www.acmicpc.net/problem/2563
#include <iostream>
using namespace std;
const int MAX = 100 + 1;
int N;
bool board[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        // 가로, 세로
        int a, b;
        cin >> a >> b;
        for (int y = a; y < a + 10; y++)
        {
            for (int x = b; x < b + 10; x++)
            {
                if (!board[y][x])
                {
                    board[y][x] = true;
                    cnt += 1;
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}