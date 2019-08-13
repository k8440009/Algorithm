// 정수 삼각형
// https://programmers.co.kr/learn/courses/30/lessons/43105
#include <bits/stdc++.h>

using namespace std;

const int MAX = 500 + 1;

int dp[MAX][MAX];

int solution(vector<vector<int>> triangle)
{
    int n = triangle.size();
    int answer = 0;

    for (int i = 0; i < triangle.size(); i++)
    {
        if (i == 0)
        {
            dp[0][0] = triangle[0][0];
            continue;
        }
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
                dp[i][j] = triangle[i][j] + dp[i - 1][j];

            else if (j == triangle[i].size() - 1)
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];

            else
                dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    for (int i = 0; i < n; i++)
        answer = max(answer, dp[n - 1][i]);

    return answer;
}