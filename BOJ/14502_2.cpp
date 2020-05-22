// 연구소 2회 : 60분
// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};
int N,M, answer;
int board[10][10];
vector <pair<int,int>> loc;

void print_board(int desc[10][10])
{
    cout << '\n';
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            cout << desc[r][c] << ' ';
        }
        cout << '\n';
    }
}
void bfs()
{
    queue <pair<int,int>> q;
    int visited[10][10];

    fill_n(visited[0], 10 * 10, 0);
    for(int i = 0; i < loc.size(); i++)
    {
        q.push(make_pair(loc[i].first, loc[i].second));
        visited[loc[i].first][loc[i].second] = 1;
    }

    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == 1 || visited[nr][nc])
                continue;
            q.push(make_pair(nr, nc));
            visited[nr][nc] = 1;
        }
    }
    int total = 0;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            if(board[r][c] == 0 && visited[r][c] == 0)
                total += 1;
    answer = max(answer, total);
    
}

void dfs(int cnt, int s_r, int s_c)
{
    if(cnt == 3)
    {
        bfs();
        return ;
    }
    for(int r = s_r; r < N; r++)
    {
        for(int c = s_c; c < M; c++)
        {
            if(board[r][c] == 0)
            {
                board[r][c] = 1;
                dfs(cnt + 1, r, c);
                board[r][c] = 0;
            }
        }
        s_c = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    answer = 0;
    cin >> N >> M;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            cin >> board[r][c];
            if(board[r][c] == 2)
                loc.push_back(make_pair(r,c));
        }
    }
    dfs(0, 0, 0);
    cout << answer << '\n';
}