// 링크와 스타트
// https://www.acmicpc.net/problem/15661
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 20;
int N, answer = 987654321;
int board[MAX][MAX];
bool selected[MAX];
void dfs(int index, int cnt)
{
    if (cnt == N / 2)
    {
        vector<int> team1, team2;
        for (int i = 0; i < N; i++)
        {
            if (selected[i])
                team1.push_back(i);
            else
                team2.push_back(i);
        }

        int zero = 0, one = 0;
        for (int y = 0; y < team1.size(); y++)
        {
            for (int x = y + 1; x < team1.size(); x++)
            {
                zero += (board[team1[y]][team1[x]] + board[team1[x]][team1[y]]);
            }
        }

        for (int y = 0; y < team2.size(); y++)
        {
            for (int x = y + 1; x < team2.size(); x++)
            {
                one += (board[team2[y]][team2[x]] + board[team2[x]][team2[y]]);
            }
        }

        answer = min(answer, abs(zero - one));
        return;
    }

    for (int i = index; i < N; i++)
    {
        selected[i] = true;
        dfs(i + 1, cnt + 1);
        selected[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];

    dfs(0, 0);

    cout << answer << '\n';
}