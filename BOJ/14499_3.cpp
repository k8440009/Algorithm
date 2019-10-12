// 주사위 굴리기
// https://www.acmicpc.net/problem/14499
#include <iostream>
using namespace std;
const int MAX = 20 + 1;
int N, M, K;
int board[MAX][MAX];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int dice[6];

void moveDice(int dir)
{
    int ndice[6];

    switch (dir)
    {
    case 0:
        ndice[0] = dice[0];
        ndice[5] = dice[1];
        ndice[2] = dice[2];
        ndice[4] = dice[3];
        ndice[1] = dice[4];
        ndice[3] = dice[5];
        break;
    case 1:
        ndice[0] = dice[0];
        ndice[4] = dice[1];
        ndice[2] = dice[2];
        ndice[5] = dice[3];
        ndice[3] = dice[4];
        ndice[1] = dice[5];
        break;
    case 2:
        ndice[3] = dice[0];
        ndice[0] = dice[1];
        ndice[1] = dice[2];
        ndice[2] = dice[3];
        ndice[4] = dice[4];
        ndice[5] = dice[5];
        break;
    case 3:
        ndice[1] = dice[0];
        ndice[2] = dice[1];
        ndice[3] = dice[2];
        ndice[0] = dice[3];
        ndice[4] = dice[4];
        ndice[5] = dice[5];
        break;
    default:
        break;
    }
    for (int i = 0; i < 6; i++)
        dice[i] = ndice[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int y, x;
    cin >> N >> M >> y >> x >> K;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
            cin >> board[r][c];
    }

    for (int i = 0; i < K; i++)
    {
        int dir;
        cin >> dir;
        dir -= 1;
        // 돌려짐
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        moveDice(dir);

        if (board[ny][nx] == 0)
            board[ny][nx] = dice[3];
        else
        {
            dice[3] = board[ny][nx];
            board[ny][nx] = 0;
        }

        y = ny;
        x = nx;

        cout << dice[1] << '\n';
    }

    return 0;
}