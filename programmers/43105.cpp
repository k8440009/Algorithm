#include <bits/stdc++.h>
using namespace std;

const int MAX = 500 + 1;
int dp[MAX][MAX];
int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            // start
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            // end
            else if (j == triangle[i].size() - 1)
            {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else
            {
                dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }
    int i = triangle.size() - 1;
    answer = dp[i][0];
    for (int j = 1; j < triangle[i].size(); j++)
        answer = max(answer, dp[i][j]);
    return answer;
}