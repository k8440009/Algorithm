// 단지번호붙이기
// https://www.acmicpc.net/problem/2667
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 25 + 1;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int N;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<int> apartCnt;
void bfs(int y, int x, int apartNum)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    int cnt = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 0)
                continue;

            if (board[ny][nx] == 1 && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                cnt += 1;
            }
        }
    }

    apartCnt.push_back(cnt);

    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            char num;
            cin >> num;
            board[y][x] = num - '0';
        }
    }

    int apart = 0;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            // 아파트이면서, 방문하지 않았던 경우
            if (board[y][x] == 1 && !visited[y][x])
            {
                bfs(y, x, apart);
                apart += 1;
            }
        }
    }

    sort(apartCnt.begin(), apartCnt.end());

    cout << apart << '\n';
    for (int i = 0; i < apartCnt.size(); i++)
        cout << apartCnt[i] << '\n';

    return 0;
}