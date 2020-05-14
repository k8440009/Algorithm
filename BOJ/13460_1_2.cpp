// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,-1,1};

struct INFO
{
    int ry,rx,by,bx,count;
};

int N, M, answer;
INFO start;

char board[12][12];

void bfs()
{
    int visited[12][12][12][12] = {0,};
    queue <INFO> q;   
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;

    while (!q.empty())
    {
        INFO cur = q.front();
        q.pop();

        if(cur.count > 10 || cur.count > answer)
            break;

        if(board[cur.ry][cur.rx] == 'O' && board[cur.by][cur.bx] != 'O')
        {
            answer = cur.count;
            break;
        }

        for(int dir = 0; dir < 4; dir++)
        {
            int next_ry = cur.ry, next_rx = cur.rx;
            int next_by = cur.by, next_bx = cur.bx;

            while (true)
            {
                if(board[next_ry][next_rx] != '#' && board[next_ry][next_rx] != 'O')
                    next_ry += dr[dir], next_rx += dc[dir];
                else
                {
                    if (board[next_ry][next_rx] == '#')
                        next_ry -= dr[dir], next_rx -= dc[dir];
                    break;
                }

            }
            while (true)
            {
                if(board[next_by][next_bx] != '#' && board[next_by][next_bx] != 'O')
                    next_by += dr[dir], next_bx += dc[dir];
                else
                {
                    if (board[next_by][next_bx] == '#')
                        next_by -= dr[dir], next_bx -= dc[dir];
                    break;
                }
            }
            // 둘이 같은 경우
            if(next_ry == next_by && next_rx == next_bx)
            {
                if(board[next_ry][next_rx] != 'O')
                {
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    if(red_dist > blue_dist)
                        next_ry -= dr[dir], next_rx -= dc[dir];
                    else
                        next_by -= dr[dir], next_bx -= dc[dir];
                }
            }

            if(visited[next_ry][next_rx][next_by][next_bx] == 0)
            {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                INFO next;
                next.ry = next_ry, next.rx = next_rx;
                next.by = next_by, next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            cin >> board[r][c];
            if(board[r][c] == 'R')
                start.ry = r, start.rx = c;
            else if(board[r][c] == 'B')
                start.by = r, start.bx = c;
        }
    }

    answer = INF;
    start.count = 0;
    bfs();
    if(answer == INF)
        answer = -1;
    cout << answer << '\n';
}