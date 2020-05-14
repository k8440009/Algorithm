// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <queue>
using namespace std;

const int dr[4] = {1,-1,0,0};
const int dc[4] = {0,0,1,-1};
const int INF = 987654321;

struct BALL
{
    int r,c;
    char color;
};

int N, M, answer;

void copy_board(char desc[12][12], char src[12][12])
{
    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            desc[r][c] = src[r][c];
}

bool check_dir(int prev_dir, int cur_dir)
{
    if(prev_dir == cur_dir)
        return false;
    else
    {
        if(prev_dir == 0 && cur_dir == 1)
            return false;
        else if(prev_dir == 1 && cur_dir == 0)
            return false;
        else if(prev_dir == 2 && cur_dir == 3)
            return false;
        else if(prev_dir == 3 && cur_dir == 2)
            return false;
    }
    return true;
    
}
void dfs(int cnt, int prev_dir, char cur_board[12][12], BALL cur_blue, BALL cur_red)
{
    if (cnt >= 10 || cnt > answer)
        return ;
    for(int dir = 0; dir < 4; dir++)
    {
        if(check_dir(prev_dir, dir))
        {
            char next_board[12][12];
            char flag = 'W';
            copy_board(next_board, cur_board);
            BALL next_blue, next_red;
            queue <BALL> q;
            q.push(cur_blue);
            q.push(cur_red);

            while (!q.empty() && flag != 'B')
            {
                BALL cur = q.front();
                q.pop();

                int nr = cur.r + dr[dir], nc = cur.c + dc[dir];
                if(next_board[nr][nc] == '#')
                {
                    next_board[cur.r][cur.c] = cur.color;
                    if(cur.color == 'R')
                        next_red.r = cur.r, next_red.c = cur.c, next_red.color = 'R';
                    else
                        next_blue.r = cur.r, next_blue.c = cur.c, next_blue.color = 'B';
                }
                else
                {
                    if(cur.color == 'R')
                    {
                        next_board[cur.r][cur.c] = '.';
                        if(next_board[nr][nc] == 'B')
                        {
                            // 파랑 구슬이 벽에 부딪힌 경우
                            if(next_board[nr + dr[dir]][nc + dc[dir]] == '#')
                            {
                                next_board[cur.r][cur.c] = cur.color;
                                next_red.r = cur.r, next_red.c = cur.c, next_red.color = 'R';
                            }
                            else
                            {
                                q.push(cur);
                                next_board[cur.r][cur.c] = cur.color;
                            }
                            
                        }
                        // 구멍
                        else if(next_board[nr][nc] == 'O')
                        {
                            if(flag != 'B')
                                flag = 'R';
                        }
                        else
                        {
                            next_board[nr][nc] = cur.color;
                            next_red.r = nr, next_red.c = nc, next_red.color = 'R';
                            BALL tmp;
                            tmp.r = nr, tmp.c = nc, tmp.color = cur.color;
                            q.push(tmp);
                        }
                    }
                    else if(cur.color == 'B')
                    {
                        next_board[cur.r][cur.c] = '.';
                        if(next_board[nr][nc] == 'R')
                        {
                            // 파랑 구슬이 벽에 부딪힌 경우
                            if(next_board[nr + dr[dir]][nc + dc[dir]] == '#')
                            {
                                next_board[cur.r][cur.c] = cur.color;
                                next_blue.r = cur.r, next_blue.c = cur.c, next_blue.color = 'B';
                            }
                            else
                            {
                                q.push(cur);
                                next_board[cur.r][cur.c] = cur.color;
                            }
                        }
                        // 구멍
                        else if(next_board[nr][nc] == 'O')
                        {
                            flag = 'B';
                            break;
                        }
                        else
                        {
                            next_board[nr][nc] = cur.color;
                            next_blue.r = nr, next_blue.c = nc, next_blue.color = 'R';
                            BALL tmp;
                            tmp.r = nr, tmp.c = nc, tmp.color = cur.color;
                            q.push(tmp);
                        }
                    }
                } 
            }
            if (flag == 'R')
            {
                if(answer == -1 || answer > cnt + 1)
                {
                    answer = cnt + 1;
                    return ;
                }
            }
            else if(flag == 'B')
                continue;
            else
                dfs(cnt + 1, dir, next_board, next_blue, next_red);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    answer = INF;
    cin >> N >> M;
    char board[12][12];
    BALL blue, red;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            cin >> board[r][c];
            if(board[r][c] == 'B')
                blue.r = r, blue.c = c, blue.color = 'B';
            else if(board[r][c] == 'R')
                red.r = r, red.c = c, red.color = 'R';
        }
    }
    dfs(0,-1,board, blue, red);
    if(answer == INF)
        answer = -1;
    cout << answer << '\n';
}