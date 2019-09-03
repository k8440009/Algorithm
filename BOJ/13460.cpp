// 구슬 탈출 2
// https://www.acmicpc.net/problem/13460
/*
    참고
    https://js1jj2sk3.tistory.com/105
    https://sangdo913.tistory.com/162
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
char board[10][11];
struct location
{
    int bX, bY; // 파란공 x,y
    int rX, rY; // 빨간공 x,y
};

location st;

bool visited[10][10][10][10]; // 빨간공, 파란공 위치

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs()
{
    queue<location> q;
    q.push(st);
    visited[st.bX][st.bY][st.rX][st.rY] = true; // 시작점
    bool escape = false;
    int time = 0;

    while (!q.empty())
    {
        int cnt = q.size();

        while (cnt--)
        {
            location now = q.front();
            q.pop();
            // 빨간공이 빠진 경우
            if (board[now.rX][now.rY] == 'O')
            {
                escape = true;
                break;
            }

            for (int dir = 0; dir < 4; dir++)
            {
                bool out[2] = {false, false};
                int t[2] = {};
                int position[2][2] = {{now.bX, now.bY}, {now.rX, now.rY}};
                // 빨간 구슬, 파란 구슬 이동
                for (int i = 0; i < 2; i++)
                {
                    while (board[position[i][0] + dx[dir]][position[i][1] + dy[dir]] != '#')
                    {
                        t[i]++;
                        position[i][0] = position[i][0] + dx[dir];
                        position[i][1] = position[i][1] + dy[dir];
                        // 이동 중 구슬이 빠진 경우
                        if (board[position[i][0]][position[i][1]] == 'O')
                            break;
                    }
                    // 탈출 여부 저장
                    out[i] = board[position[i][0]][position[i][1]] == 'O';
                }
                // 파란공이 탈출 했다면
                if (out[0])
                    continue;
                // 파란공 위치랑 파란공 위치가 같은 경우
                if (position[0][0] == position[1][0] && position[0][1] == position[1][1])
                {
                    // 시간 차이로 구분
                    if (t[0] > t[1])
                        position[0][0] -= dx[dir], position[0][1] -= dy[dir];
                    else
                        position[1][0] -= dx[dir], position[1][1] -= dy[dir];
                }
                // 이미 방문한 지점인 경우 패스
                if (visited[position[0][0]][position[0][1]][position[1][0]][position[1][1]])
                    continue;
                visited[position[0][0]][position[0][1]][position[1][0]][position[1][1]] = true;
                // 다음 이동
                location next = {position[0][0],
                                 position[0][1],
                                 position[1][0],
                                 position[1][1]};
                q.push(next);
            }
        }
        // 탈출한 경우
        if (escape)
            break;
        time++; //아닌 경우
        if (time > 10)
            break;
    }
    return escape ? time : -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            // 빨간 공 위치
            if (board[i][j] == 'R')
            {
                st.rX = i;
                st.rY = j;
                board[i][j] = '.';
            }
            // 파란공 위치
            else if (board[i][j] == 'B')
            {
                st.bX = i;
                st.bY = j;
                board[i][j] = '.';
            }
        }
    }

    cout << bfs();
    return 0;
}