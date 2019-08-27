// 1215. [S/W 문제해결 기본] 3일차 - 회문1 (팰린드롬)
#include <iostream>
#include <string>
using namespace std;
const int MAX = 8;
int dp[MAX][MAX];
char board[MAX][MAX];
int n;

bool dfs(int start, int end, string str)
{
    // 팰린 드롬 길이
    //길이 1 (홀수)
    if (start == end)
        return true;
    // 길이 2 짝수
    else if (start + 1 == end)
    {
        if (str[start] == str[end])
            return true;
        else
            return false;
    }
    // 팰린 드롬이 아니면 false
    if (str[start] != str[end])
        return false;
    else
        return dfs(start + 1, end - 1, str);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    while (tc <= 10)
    {
        int cnt = 0; // 회문 갯수
        cin >> n;

        for (int i = 0; i < MAX; i++)
        {
            string str;
            cin >> str;

            for (int j = 0; j < MAX; j++)
            {
                board[i][j] = str[j];
            }
        }

        for (int i = 0; i < MAX; i++)
        {
            string str1 = "";
            string str2 = "";
            for (int j = 0; j < MAX; j++)
            {
                str1 += board[i][j]; //가로
                str2 += board[j][i]; // 세로
            }

            for (int j = 0; j <= MAX - n; j++)
            {
                int start = j;
                int end = j + n - 1;
                // 가로
                if (dfs(start, end, str1))
                    cnt++;
                // 세로
                if (dfs(start, end, str2))
                    cnt++;
            }
        }
        cout << "#" << tc << ' ' << cnt << '\n';
        tc++;
    }

    return 0;
}