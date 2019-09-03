// 탈옥
// https://www.acmicpc.net/problem/9376
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
vector<string> board;
vector<vector<int>> bfs(int x, int y)
{   
    int n = board.size();
    int m = board[0].size();

    vector <vector <int>> d(n,vector <int> (m));
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        board.resize(n + 2);
        for (int i = 1; i <= n; i++)
        {
            cin >> board[i];
            board[i] = "." + board[i] + ".";
        }

        h += 2;
        w += 2;

        for (int i = 0; i < m; i++)
        {
            board[0] += ".";
            board[n - 1] += ".";
        }

        vector<vector<int>> dist1 = bfs(0, 0);
    }

    return 0;
}