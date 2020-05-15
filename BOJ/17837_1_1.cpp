#include <iostream>
#include <vector>
using namespace std;

struct INFO
{
    int r,c,dir;
};

const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0}; 
int N,K, answer;
int state_board[14][14];
vector <INFO> board[14][14];
vector <INFO> knights;

int change_dir(int dir)
{
    if(dir == 1)
        return 2;
    else if(dir == 2)
        return 1;
    else if (dir == 3)
        return 2;
    else if(dir == 4)
        return 3;
}

void blue(INFO cur, int size)
{
    cur.dir = change_dir(cur.dir);
    int nr = cur.r + dr[cur.dir], nc = cur.c + dc[cur.dir];
    if(nr < 0 || nr >= N || nc < 0 || nc >= N || state_board[nr][nc] == 2)
    board[nr][nc].push_back(cur);
}
void solve()
{
    
    int time = 0;
    while (time < 1000)
    {
        for(int k = 0; k < K; k++)
        {
            INFO cur = knights[k];
            int nr = cur.r + dr[cur.dir], nc = cur.c + dc[cur.dir];
            
        }
        time++;
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    answer = -1;
    cin >> N >> K;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            cin >> state_board[r][c];
    for(int k = 0; k < K; k++)
    {
        INFO tmp;
        cin >> tmp.r >> tmp.c >> tmp.dir;
        tmp.r -=1, tmp.c -=1, tmp.dir -=1;
        board[tmp.r][tmp.c] = tmp;
        knights.push_back(tmp);
    }
    solve();
}