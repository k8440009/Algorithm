// 원판 돌리기 - 2회 90분
// https://www.acmicpc.net/problem/17822
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0};

struct INFO
{
    int x,d,k;
};

int N,M,T;
int board[52][52];
int visited[52][52];

void print_board(int desc[52][52])
{
    cout << '\n';
    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= M; c++)
        {
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }
}

void delete_number()
{
    bool flag = false;
    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= M; c++)
        {
            if(board[r][c] == 0)
                continue;
            fill_n(visited[0], 52 * 52, 0);
            vector <pair<int,int>> loc;
            queue <pair<int,int>> q;
            int num = board[r][c];

            q.push(make_pair(r,c));
            loc.push_back(make_pair(r,c));
            visited[r][c] = 1;
            while (!q.empty())
            {
                pair<int,int> cur = q.front();
                q.pop();

                for(int dir = 0; dir < 4; dir++)
                {
                    int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
                    if(nr < 1 || nr >= N + 1 || visited[nr][nc])
                        continue;
                    if(nc < 1)
                    {
                        if(!visited[cur.first][M] && board[cur.first][M] == num)
                        {
                            q.push(make_pair(cur.first, M));
                            visited[cur.first][M] = 1;
                            loc.push_back(make_pair(cur.first, M));
                        }
                    }
                    else if(nc >= M + 1)
                    {
                        if(!visited[cur.first][1] && board[cur.first][1] == num)
                        {
                            q.push(make_pair(cur.first, 1));
                            visited[cur.first][1] = 1;
                            loc.push_back(make_pair(cur.first, 1));
                        }
                    }
                    else if(board[nr][nc] == num)
                    {
                        q.push(make_pair(nr,nc));
                        visited[nr][nc] = 1;
                        loc.push_back(make_pair(nr,nc));
                    }
                }
            }
            if(loc.size() > 1)
            {
                for(int i = 0; i < loc.size(); i++)
                    board[loc[i].first][loc[i].second] = 0;
                flag = true;
            }
        }
    }

    if(!flag)
    {
        int total = 0, count = 0;
        for(int r = 1; r <= N; r++)
        {
            for(int c = 1; c <= M; c++)
            {
                if(board[r][c] > 0)
                {
                    total += board[r][c];
                    count += 1;
                }
            }
        }

        if(count > 0)
        {
            double avg = double(total) / count;
            for(int r = 1; r <= N; r++)
            {
                for(int c = 1; c <= M; c++)
                {
                    if(board[r][c] > 0)
                    {
                        if(double(board[r][c]) > avg)
                            board[r][c] -= 1;
                        else if(double(board[r][c]) < avg)
                            board[r][c] += 1;
                    }
                }
            }
        }
    }
}

void right(int r, int k)
{
    k %= M;
    for(int cnt = 0; cnt < k; cnt++)
    {
        int tmp = board[r][M];
        for(int c = M; c >= 2; c--)
            board[r][c] = board[r][c - 1];
        board[r][1] = tmp;
    }
}

void left(int r, int k)
{
    k %= M;
    for(int cnt = 0; cnt < k; cnt++)
    {
        int tmp = board[r][1];
        for(int c = 2; c <= M; c++)
            board[r][c - 1] = board[r][c];
        board[r][M] = tmp;
    }
}

void rotate(INFO data)
{
    for (int r = 2; r <= N; r++)
    {
        if(r % (data.x) == 0)
        {
            if (data.d == 0)
                right(r, data.k);
            else
                left(r, data.k);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> T;
    for(int r = 1; r <= N; r++)
        for(int c = 1; c <= M; c++)
            cin >> board[r][c];
    for(int i = 0; i < T; i++)
    {
        INFO tmp;
        cin >> tmp.x >> tmp.d >> tmp.k;
        rotate(tmp);
        delete_number();
    }
    int answer = 0;
    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= M; c++)
        {
            if(board[r][c] > 0)
                answer += board[r][c];
        }
    }
    cout << answer << '\n';
}