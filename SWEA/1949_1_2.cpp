// 1949. [모의 SW 역량테스트] 등산로 조성
#include <iostream>
using namespace std;

struct INFO
{
    int r, c, height, used, len;
};

const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,-1,1};

int N,K, answer;
int board[10][10];
bool visited[10][10];

void dfs(INFO cur)
{
    answer = answer > cur.len ? answer : cur.len;

    for(int dir = 0; dir < 4; dir++)
    {
        INFO next = cur;
        next.r += dr[dir], next.c += dc[dir];

        if(next.r < 0 || next.r >= N || next.c < 0 || next.c >= N || visited[next.r][next.c])
            continue;
        next.height = board[next.r][next.c];
        if(next.height < cur.height)
        {
            visited[next.r][next.c] = 1;
            next.len += 1;
            dfs(next);
            visited[next.r][next.c] = 0;
        }
        else
        {
            if(cur.used == 0 && next.height - K < cur.height)
            {
                visited[next.r][next.c] = 1;
                next.len += 1;
                next.used = 1;
                next.height = cur.height - 1;
                dfs(next);
                visited[next.r][next.c] = 0;
            }
        }   
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for(int ts = 1; ts <= tc; ts++)
    {
        fill_n(visited[0], 10 * 10, 0);
        answer = 0;
        int max_height = 0;
        cin >> N >> K;
        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < N; c++)
            {
                cin >> board[r][c];
                max_height = board[r][c] > max_height ? board[r][c] : max_height;
            }
        }

        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < N; c++)
            {
                if(max_height == board[r][c])
                {
                    if(max_height == board[r][c])
                    {
                        visited[r][c] = 1;
                        INFO cur;
                        cur.r = r, cur.c = c, cur.height = board[r][c], cur.used = 0, cur.len = 1;
                        dfs(cur);
                        visited[r][c] = 0;

                    }
                }
            }
        }
        cout << "#" << ts << ' ' << answer << '\n';
    }
}