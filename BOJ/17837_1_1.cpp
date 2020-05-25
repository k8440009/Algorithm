// 새로운 게임 2 - 1회 6시간
// https://www.acmicpc.net/problem/17837
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int dr[] = {0,0,0,-1,1};
const int dc[] = {0,1,-1,0,0};

struct HORSE
{
    int r, c, dir;
};

int N,K, answer;
int color[14][14];
vector <int> board[14][14];
vector <HORSE> loc;

int change_dir(int dir)
{
    if(dir == 1)
        return 2;
    else if(dir == 2)
        return 1;
    else if(dir == 3)
        return 4;
    else if(dir == 4)
        return 3;
}

int red(vector<int> data, int k)
{
    int cnt = 0;
    int nr = loc[k].r + dr[loc[k].dir], nc = loc[k].c + dc[loc[k].dir];
    for(int i = data.size() - 1; i >= 0; i--)
    {
        board[nr][nc].push_back(data[i]);
        loc[data[i]].r = nr, loc[data[i]].c = nc;
    }
    cnt = board[nr][nc].size();
    return cnt;
}

int white(vector<int> data, int k)
{
    int cnt = 0;
    int nr = loc[k].r + dr[loc[k].dir], nc = loc[k].c + dc[loc[k].dir];
    for(int i = 0; i < data.size(); i++)
    {
        board[nr][nc].push_back(data[i]);
        loc[data[i]].r = nr, loc[data[i]].c = nc;
    }
    cnt = board[nr][nc].size();
    return cnt;
}

int blue(int k)
{
    int cnt = 0;
    int nr = loc[k].r + dr[loc[k].dir], nc = loc[k].c + dc[loc[k].dir];
    if(nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1 || color[nr][nc] == 2)
        return cnt;
    else
    {
        int idx;
        vector <int> tmp;
        for(int i = 0; i < board[loc[k].r][loc[k].c].size(); i++)
        {
            if(k == board[loc[k].r][loc[k].c][i])
            {
                idx = i;
                break;
            }
        }
        for(int i = idx; i < board[loc[k].r][loc[k].c].size(); i++)
            tmp.push_back(board[loc[k].r][loc[k].c][i]);
        for(int i = 0; i < tmp.size(); i++)
            board[loc[k].r][loc[k].c].pop_back();
        if(color[nr][nc] == 0)
            cnt = white(tmp,k);
        else if(color[nr][nc] == 1)
            cnt = red(tmp,k);
    }
    return cnt;
    
}

void solve()
{
    int time = 1;
    while (time <= 1000)
    {
        for(int k = 0; k < K; k++)
        {
            int cnt = 0;
            int nr = loc[k].r + dr[loc[k].dir], nc = loc[k].c + dc[loc[k].dir];
            if(nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1 || color[nr][nc] == 2)
            {
                loc[k].dir = change_dir(loc[k].dir);
                cnt = blue(k);
            }
            else
            {
                int idx;
                vector <int> tmp;
                for(int i = 0; i < board[loc[k].r][loc[k].c].size(); i++)
                {
                    if(k == board[loc[k].r][loc[k].c][i])
                    {
                        idx = i;
                        break;
                    }
                }
                for(int i = idx; i < board[loc[k].r][loc[k].c].size(); i++)
                    tmp.push_back(board[loc[k].r][loc[k].c][i]);
                for(int i = 0; i < tmp.size(); i++)
                    board[loc[k].r][loc[k].c].pop_back();
                if(color[nr][nc] == 0)
                    cnt = white(tmp,k);
                else if(color[nr][nc] == 1)
                    cnt = red(tmp,k);
            }
            if(cnt >= 4)
            {
                answer = time;
                return ;
            }
        }
        time++;
    } 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    answer = INF;
    cin >> N >> K;
    for(int r = 1; r <= N; r++)
        for(int c = 1; c <= N; c++)
            cin >> color[r][c];
    for(int i = 0; i < K; i++)
    {
        HORSE tmp;
        cin >> tmp.r >> tmp.c >> tmp.dir;
        board[tmp.r][tmp.c].push_back(i);
        loc.push_back(tmp);
    }
    solve();
    if(answer == INF)
        answer = -1;
    cout << answer << '\n';
}