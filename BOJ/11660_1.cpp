// 구간 합 구하기 5
// https://www.acmicpc.net/problem/11660
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1024 + 1;
int board[MAX][MAX];
int cache[MAX][MAX];
int N, M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int y = 1; y <= N; y++)
    {
        int sum = 0;
        for (int x = 1; x <= N; x++)
        {
            cin >> board[y][x];
            sum += board[y][x];
            cache[y][x] = sum;
        }
    }

    while (M--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for (int start = x1; start <= x2; start++)
            sum += (cache[start][y2] - cache[start][y1 - 1]);
        cout << sum << "\n";
    }

    return 0;
}
