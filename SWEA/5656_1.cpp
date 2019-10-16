// 5656. [모의 SW 역량테스트] 벽돌 깨기
/*
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, W, H, answer;
const int wMAX = 12 + 1;
const int hMAX = 15 + 1;
int board[wMAX][hMAX];

void dfs(int cnt, int sx, int board[][hMAX])
{
    if (cnt == N)
    {
        int cnt = 0;
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                if (board[y][x] > 0)
                    cnt += 1;
            }
        }

        answer = min(answer, cnt);

        return;
    }

    int copyBoard[wMAX][hMAX];
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            copyBoard[y][x] = board[y][x];

    // 파괴 망가!
    int y = 0;
    int x = sx;
    while (y < H)
    {
        if (copyBoard[y][x] == 0)
            y += 1;
        else
            break;
    }
    // 파괴
    if (y != H)
    {
        int destory = copyBoard[y][x] - 1;
        copyBoard[y][x] = 0;

        int ny = y - 1;
        // 왼쪽
        for (int i = 1; i <= destory; i++)
        {
            int nx = x - i;
            if (nx < 0 || nx >= W)
                break;
            if (board[nx][y] > 0)
            {
                destory();
            }
            board[nx][y] = 0;
        }
        // 오른쪽
        // 아래
    }

    for (int i = 0; i < W; i++)
    {
        dfs(cnt + 1, i, copyBoard);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        answer = 987654321;
        cin >> N >> W >> H;
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                cin >> board[y][x];
            }
        }

        for (int x = 0; x < W; x++)
        {
            // 구슬,
            dfs(0, x, board);
        }

        cout << "#" << ts << ' ' << answer;
    }
    return 0;
}
*/