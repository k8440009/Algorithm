// 뱀 2회 - 35분
// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

struct HEAD
{
    int r, c, dir;
};
int N, K, L;
int answer;

int board[102][102];
int body[102][102];

vector <pair<int, char>> chage_dir;

void solve()
{
    queue <pair<int,int>> q;
    HEAD head;
    int time = 0, idx = 0;
    head.r = 1, head.c = 1, head.dir = 1;
    q.push(make_pair(1,1));
    while (true)
    {
        if (time == chage_dir[idx].first)
        {
            if(chage_dir[idx].second == 'L')
                head.dir = ((head.dir - 1) + 4) % 4;
            else
                head.dir = (head.dir + 1) % 4;
            idx++;
        }
        // 머리가 움직임 
        int nr = head.r + dr[head.dir], nc = head.c + dc[head.dir];
        if(nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1 || body[nr][nc] == 1)
            break;
        pair<int,int> tmp;
        // 몸늘림
        head.r = nr, head.c = nc;
        tmp.first = nr, tmp.second = nc;
        q.push(tmp);
        body[nr][nc] = 1;
        // 사과 있음
        if(board[nr][nc] == 1)
        {
            board[nr][nc] = 0;
        }
        // 없음
        else
        {
            pair<int,int> cur = q.front();
            q.pop();
            body[cur.first][cur.second] = 0;
        }
        time++;
    }
    answer = time + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    answer = 0;
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int r,c;
        cin >> r >> c;
        board[r][c] = 1;
    }
    cin >> L;
    chage_dir.resize(L);
    for(int i = 0; i < L; i++)
        cin >> chage_dir[i].first >> chage_dir[i].second;
    solve();
    cout << answer << '\n';
}