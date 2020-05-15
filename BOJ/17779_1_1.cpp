// 게리맨더링 2
// https://www.acmicpc.net/problem/17779
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = 987654321;
int board[22][22];
int visited[22][22];

void solve(int x, int y, int e_d1, int e_d2, int total)
{
    fill_n(visited[0], 22 * 22, 0);
    // 경계선
    int s_d1, s_d2, r, c;
    s_d1 = 0, s_d2 = 0, r = 1; c = 1;
    while (s_d1 <= e_d1)
    {
        r = x + s_d1, c = y - s_d1;
        if(r < 1 || r >= N + 1 || c < 1 || c >= N + 1)
            break;
        visited[r][c] = 5;
        s_d1++;
    }
    s_d1 = 0, s_d2 = 0, r = 1; c = 1;
    while (s_d2 <= e_d2)
    {
        r = x + s_d2, c = y + s_d2;
        if(r < 1 || r >= N + 1 || c < 1 || c >= N + 1)
            break;
        visited[r][c] = 5;
        s_d2++;
    }
     s_d1 = 0, s_d2 = 0, r = 1; c = 1;
    while (s_d2 <= e_d2)
    {
        r = x + e_d1 + s_d2, c = y - e_d1 + s_d2;
        if(r < 1 || r >= N + 1 || c < 1 || c >= N + 1)
            break;
        visited[r][c] = 5;
        s_d2++;
    }
    s_d1 = 0, s_d2 = 0, r = 1; c = 1;
    while (s_d1 <= e_d1)
    {
        r = x + e_d2 + s_d1, c = y + e_d2 - s_d1;
        if(r < 1 || r >= N + 1 || c < 1 || c >= N + 1)
            break;
        visited[r][c] = 5;
        s_d1++;
    }

    vector <int> people;
    people.resize(5, 0);
    for(int r = 1; r < x + e_d1; r++)
    {
        for(int c = 1; c <= y; c++)
        {
            if(visited[r][c] == 5)
                break;
            visited[r][c] = 1;
            people[0] += board[r][c];
        }
    }
    for(int r = x + e_d2; r >= 1; r--)
    {
        for(int c = N; c > y; c--)
        {
            if(visited[r][c] == 5)
                break;
            visited[r][c] = 2;
            people[1] += board[r][c];
        }
    }
    for(int r = x + e_d1; r <= N; r++)
    {
        for(int c = 1; c < y - e_d1 + e_d2; c++)
        {
            if(visited[r][c] == 5)
                break;
            visited[r][c] = 3;
            people[2] += board[r][c];
        }
    }

    for(int r = N; r > x + e_d2; r--)
    {
        for(int c = N; c >= y - e_d1 + e_d2; c--)
        {
            if(visited[r][c] == 5)
                break;
            visited[r][c] = 4;
            people[3] += board[r][c];
        }
    }
    people[4] = total - people[0] - people[1] - people[2] - people[3];
    sort(people.begin(), people.end());
    answer = min(answer, people[4] - people[0]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int total = 0;
    cin >> N;
    for(int r = 1; r <= N; r++)
        for(int c = 1; c <= N; c++)
        {
            cin >> board[r][c];
            total += board[r][c];
        }
    
    for(int d1 = 1; d1 < N; d1++)
    {
        for(int d2 = 1; d2 < N; d2++)
        {
            for(int x = 1; x + d1 + d2 < N; x++)
            {
                for(int y = 1; y + d2 < N; y++)
                {
                    if(y - d1 >= 1)
                        solve(x,y,d1,d2, total);
                }
            }
        }
    }
    cout << answer << '\n';
}