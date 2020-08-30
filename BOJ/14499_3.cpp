// 주사위 굴리기
// https://www.acmicpc.net/problem/14499
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20 + 1;
const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0};
vector <int> move_dir;
int N,M,R,C,K;
int dice[6];
int board[MAX][MAX];

void move_dice(int dir)
{
    if (dir == 0)
    {
        int tmp = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = tmp;
    }
    else if (dir == 1)
    {
        int tmp = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[0];
        dice[0] = tmp;
    }
    else if (dir == 2)
    {
        int tmp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
    }
    else if (dir == 3)
    {
        int tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = tmp;
    }
}

void solve()
{
    int r = R, c = C;
    for (int i = 0; i < move_dir.size(); i++)
    {
        int dir = move_dir[i];
        int nr = r + dr[dir], nc = c + dc[dir];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;
        // 주사위 움직임
        move_dice(dir);
        if (board[nr][nc] == 0)
             board[nr][nc] = dice[5];
        else
        {
            dice[5] = board[nr][nc];
            board[nr][nc] = 0;
        }
        r = nr, c = nc;
        cout << dice[0] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R >> C >> K;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> board[r][c];
    for (int k = 0; k < K; k++)
    {
        int dir;
        cin >> dir;
        move_dir.push_back(--dir);
    }
    solve();
}