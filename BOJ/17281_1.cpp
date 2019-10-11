// 야구
// https://www.acmicpc.net/problem/17281
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 50 + 2;
int N, answer = 0;
int table[MAX][9];
bool selected[10];
int ordered[10];
void play()
{
    bool board[4];
    fill_n(board, 4, 0);
    // 이닝, 순서
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    int score = 0, outCount = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.second == 10)
            cur.second = 1;

        int hitter = table[cur.first][ordered[cur.second]];
        // 아웃
        if (hitter == 0)
        {
            outCount += 1;
            // 다음 이닝
            if (outCount == 3)
            {
                if (cur.first + 1 <= N)
                {
                    q.push(make_pair(cur.first + 1, cur.second + 1));
                    fill_n(board, 4, 0);
                    outCount = 0;
                }
                else
                {
                    answer = max(answer, score);
                    return;
                }
            }
            else
            {
                q.push(make_pair(cur.first, cur.second + 1));
            }
        }
        // 안타
        else if (hitter == 1)
        {
            // 3루
            if (board[3])
            {
                board[3] = false;
                score += 1;
            }
            // 2루
            if (board[2])
            {
                board[2] = false;
                board[3] = true;
            }
            // 1루
            if (board[1])
            {
                board[2] = true;
                board[1] = false;
                // board[1] = true;
            }

            board[1] = true;
            q.push(make_pair(cur.first, cur.second + 1));
        }
        // 2루타
        else if (hitter == 2)
        {
            // 3루
            if (board[3])
            {
                board[3] = false;
                score += 1;
            }
            // 2루
            if (board[2])
            {
                board[2] = false;
                score += 1;
            }
            // 1루
            if (board[1])
            {
                board[1] = false;
                board[3] = true;
            }

            board[2] = true;
            q.push(make_pair(cur.first, cur.second + 1));
        }
        // 3루타
        else if (hitter == 3)
        {
            // 3루
            if (board[3])
            {
                board[3] = false;
                score += 1;
            }
            // 2루
            if (board[2])
            {
                board[2] = false;
                score += 1;
            }
            // 1루
            if (board[1])
            {
                board[1] = false;
                score += 1;
            }

            board[3] = true;
            q.push(make_pair(cur.first, cur.second + 1));
        }
        // 홈런
        else if (hitter == 4)
        {
            score += 1; // 타자
            for (int i = 1; i <= 3; i++)
            {
                if (board[i])
                {
                    board[i] = false;
                    score += 1;
                }
            }
            q.push(make_pair(cur.first, cur.second + 1));
        }
    }
}

void dfs(int index)
{
    if (index == 10)
    {
        play();
        return;
    }
    // 2번 선수 부터
    for (int i = 2; i <= 9; i++)
    {
        if (!selected[i])
        {
            ordered[index] = i;
            selected[i] = true;
            if (index == 3)
                dfs(index + 2);
            else
                dfs(index + 1);
            selected[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= 9; x++)
        {
            cin >> table[y][x];
        }
    }

    selected[1] = true;
    ordered[4] = 1;

    // 번호 1번
    dfs(1);
    cout << answer << '\n';
    return 0;
}