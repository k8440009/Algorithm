// 뱀
// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100 + 2;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

struct HEAD
{
    int r, c, dir;
};

int N, K, L;
int answer;
int board[MAX][MAX];
int body[MAX][MAX];

vector <pair<int,char>> change_dir;

void solve()
{
    queue <pair<int,int>> q;
    HEAD head;
    int time = 0, idx = 0;


    head.r = 1, head.c = 1, head.dir = 1;
    q.push(make_pair(1,1));
    body[head.r][head.c] = 1;
    while (true)
    {
        // 시간 증가
        if (time == change_dir[idx].first)
        {
            if (change_dir[idx].second == 'L')
                head.dir = ((head.dir - 1) + 4) % 4;
            else
                head.dir = ((head.dir + 1) + 4) % 4;
            idx++;
        }
        int nr = head.r + dr[head.dir], nc = head.c + dc[head.dir];
        if (nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1 || body[nr][nc])
            break;
        head.r = nr, head.c = nc;
        q.push(make_pair(nr, nc));
        body[nr][nc] = 1;
        if (board[nr][nc] == 1)
            board[nr][nc] = 0;
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

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }
    cin >> L;
    change_dir.resize(L);
    for (int i = 0; i < L; i++)
        cin >> change_dir[i].first >> change_dir[i].second;
    solve();
    cout << answer << '\n';
}