// 5656. 줄기세포배양
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 50;
int N, M, K;
int board[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> N >> M >> K;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                cin >> board[y][x];
            }
        }

        for (int time = 0; time < K; time++)
        {
                }
        cout << "#" << ts << ' ';
    }
    return 0;
}