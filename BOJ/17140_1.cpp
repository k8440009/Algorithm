// 이차원 배열과 연산
// https://www.acmicpc.net/problem/17140
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using namespace std;
const int MAX = 100 + 1;
int R, C, K;
int board[MAX][MAX];
int num[MAX];
int colCal(int r, int c)
{
    return r;
}
int rowCal(int N, int M)
{
    int cnt = 0;
    for (int r = 0; r < N; r++)
    {
        map<int, int> m;
        for (int c = 0; c < M; c++)
        {
            if (board[r][c] == 0)
                continue;
            m[board[r][c]] += 1;
        }
        // 등장 횟수, 숫자
        vector<pair<int, int>> v(MAX);
        map<int, int>::iterator iter;
        for (iter = m.begin(); iter != m.end(); iter++)
        {
            // 등장 횟수, 숫자
            v.push_back(make_pair(iter->second, iter->first));
        }

        sort(v.begin(), v.end());

        int index = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (index < 100)
            {
                board[r][index] = v[i].second; // 숫자
                index += 1;
            }
            if (index < 100)
            {
                board[r][index] = v[i].first; // 횟수
                index += 1;
            }
        }

        cnt = max(cnt, index);
    }

    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> K;
    R -= 1, C -= 1;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cin >> board[r][c];
        }
    }

    int time = 0;
    int row = 3;
    int col = 3;
    while (time <= 100)
    {
        if (board[R][C] == K)
            break;
        if (row >= col)
        {
            row = rowCal(row, col);
        }
        else
        {
            col = colCal(row, col);
        }

        time += 1;
    }
    if (time == 101)
        time = -1;
    cout << time << '\n';
}