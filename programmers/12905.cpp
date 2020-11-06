// 가장 큰 정사각형 찾기
// https://programmers.co.kr/learn/courses/30/lessons/12905
/*
    브포는 됨
    dp써야함

#include <bits/stdc++.h>
using namespace std;
int n, m;
bool find(int y, int x, int range, vector<vector<int>> &board)
{
    for (int i = y; i < y + range; i++)
    {
        for (int j = x; j < x + range; j++)
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
    n = board.size();
    m = board[0].size();

    int len = min(n, m);

    while (len > 0)
    {
        bool check = true;
        for (int i = 0; i < n - (len - 1); i++)
        {
            for (int j = 0; j < m - (len - 1); j++)
            {
                if (find(i, j, len, board))
                {
                    answer = len * len;
                    return answer;
                }
            }
        }

        len--;
    }

    return answer;
}
*/