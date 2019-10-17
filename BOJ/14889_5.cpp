// 스타트와 링크
// https://acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20 + 1;
const int INF = 987654321;
int N, answer = INF;
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
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = i + 1; j < N / 2; j++)
            {
                zero += board[team1[i]][team1[j]] + board[team1[j]][team1[i]];
                one += board[team2[i]][team2[j]] + board[team2[j]][team2[i]];
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
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
        }
    }

    answer = INF;
    dfs(0, 0); // dfs(index, cnt)
    cout << answer << '\n';
    return 0;
}