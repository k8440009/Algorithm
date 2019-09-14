// 가장 큰 정사각형 찾기
// https://programmers.co.kr/learn/courses/30/lessons/12905
#include <bits/stdc++.h>
using namespace std;

bool find(int y, int x, int range, vector<vector<int>> &board)
{
    for (int i = y; i < range; i++)
    {
        for (int j = x; j < range; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }

    return true;
}
int solution(vector<vector<int>> board)
{
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    int len = 1;
    while (len <= min(n, m))
    {
        for (int i = 0; i < n - (len - 1); i++)
        {
            for (int j = 0; j < m - (len - 1); j++)
            {
                if (find(j, i, len, board))
                {
                    answer = len * len;
                    break;
                }
            }
        }
        len++;
    }

    return answer;
}