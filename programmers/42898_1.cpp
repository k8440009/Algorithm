// 등굣길
// https://programmers.co.kr/learn/courses/30/lessons/42898
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 100 + 1;
const ll MOD = 1000000007;
int board[MAX][MAX];
ll dp[MAX][MAX];
int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++)
    {
        board[puddles[i][1]][puddles[i][0]] = -1;
    }

    dp[1][0] = 1;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (board[y][x] == -1)
                dp[y][x] = 0;
            else
                dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]) % MOD;
        }
    }

    return dp[n][m];
}