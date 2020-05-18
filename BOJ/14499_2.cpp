// 주사위 굴리기 - 2회 시간 : 36분
// https://www.acmicpc.net/problem/14499
#include <iostream>
#include <vector>
using namespace std;

const int dr[] = {0,0,0,-1,1};
const int dc[] = {0,1,-1,0,0};
struct DICE
{
    int r, c, dir;
};

int dice_data[6];
int board[22][22];
DICE dice;
vector <int> command;
int N, M, K;

void move_dice(int dir)
{
    // 동
    if(dir == 1)
    {
        int tmp = dice_data[0];
        dice_data[0] = dice_data[3];
        dice_data[3] = dice_data[5];
        dice_data[5] = dice_data[2];
        dice_data[2] = tmp;
    }
    // 서
    else if(dir == 2)
    {
        int tmp = dice_data[0];
        dice_data[0] = dice_data[2];
        dice_data[2] = dice_data[5];
        dice_data[5] = dice_data[3];
        dice_data[3] = tmp;
    }
    // 북
    else if(dir == 3)
    {
        int tmp = dice_data[0];
        dice_data[0] = dice_data[4];
        dice_data[4] = dice_data[5];
        dice_data[5] = dice_data[1];
        dice_data[1] = tmp;
    }
    else
    {
        int tmp = dice_data[0];
        dice_data[0] = dice_data[1];
        dice_data[1] = dice_data[5];
        dice_data[5] = dice_data[4];
        dice_data[4] = tmp;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> dice.r >> dice.c >> K;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            cin >> board[r][c];
    command.resize(K);
    for(int i = 0; i < K; i++)
        cin >> command[i];
    for(int i = 0; i < K; i++)
    {
        int nr = dice.r + dr[command[i]], nc = dice.c + dc[command[i]];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;
        move_dice(command[i]);
        if(board[nr][nc] == 0)
            board[nr][nc] = dice_data[5];
        else
        {
            dice_data[5] = board[nr][nc];
            board[nr][nc] = 0;
        }
        dice.r = nr, dice.c = nc;
        cout << dice_data[0] << '\n';
    }
}