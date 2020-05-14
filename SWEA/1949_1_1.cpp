// 1949. [모의 SW 역량테스트] 등산로 조성
#include <iostream>
#include <queue>
using namespace std;

const int dr[4] = {1,-1,0,0};
const int dc[4] = {0,0,1,-1};
struct STATE
{
    bool flag;
    int r, c, cnt;
};

int N,K, answer;

void copy_visited(bool desc[10][10], bool src[10][10])
{
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            desc[r][c] = src[r][c];
}

void copy_board(int desc[10][10], int src[10][10])
{
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            desc[r][c] = src[r][c];
}

void dfs(STATE start, int cur_board[10][10], bool cur_visited[10][10])
{
    for (int dir = 0; dir < 4; dir++)
    {
        int nr = start.r + dr[dir], nc = start.c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N || cur_visited[nr][nc])
            continue;
        STATE tmp;
        if(cur_board[start.r][start.c] > cur_board[nr][nc])
        {
            bool next_visited[10][10];
            copy_visited(next_visited, cur_visited);
            tmp.r = nr, tmp.c = nc, tmp.cnt = start.cnt + 1, tmp.flag = start.flag;
            next_visited[nr][nc] = 1;
            dfs(tmp, cur_board, next_visited);
        }
        else if((cur_board[start.r][start.c] <= cur_board[nr][nc]) && start.flag == 0)
        {
            for(int k = 1; k <= K; k++)
            {
                if (cur_board[nr][nc] - k < 0)
                    break;
                if (cur_board[start.r][start.c] > cur_board[nr][nc] - k)
                {
                    int next_board[10][10];
                    bool next_visited[10][10];
                    copy_board(next_board, cur_board);
                    copy_visited(next_visited, cur_visited);
                    tmp.r = nr, tmp.c = nc, tmp.cnt = start.cnt + 1, tmp.flag = 1;
                    next_board[nr][nc] -= k;
                    next_visited[nr][nc] = 1;
                    dfs(tmp,next_board,next_visited);
                }
            }
        }
    }

   answer = max(answer, start.cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sample_input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int ts = 1; ts <= tc; ts++)
    {
        cin >> N >> K;
        int board[10][10];
        fill_n(board[0], 10 * 10, 0);
        int max_height = 0;
        answer = 0;
        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < N; c++)
            {
                cin >> board[r][c];
                if(board[r][c] > max_height)
                    max_height = board[r][c];
            }
        }
        // 봉우리 체크
        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < N; c++)
            {
                if(board[r][c] == max_height)
                {
                    STATE tmp;
                    int cur_board[10][10];
                    bool visited[10][10];
                    fill_n(visited[0], 10  * 10, 0);
                    copy_board(cur_board, board);
                    tmp.r = r, tmp.c = c, tmp.cnt = 1, tmp.flag = 0;
                    visited[r][c] = 1;
                    dfs(tmp, cur_board, visited);
                }
            }
        }
        cout << "#" << ts << ' ' << answer << '\n'; 
    }
}