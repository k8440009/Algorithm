// 스타트와 링크
// https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20;
const int INF = 987654321;
int N, answer;
int board[MAX][MAX];
bool visited[MAX];
void setTeam(int index, int cnt)
{
    if (cnt == N / 2)
    {
        vector<int> team1, team2;
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
                team1.push_back(i);
            else
                team2.push_back(i);
        }

        int zero = 0, one = 0;
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = i + 1; j < N / 2; j++)
            {
                zero += (board[team1[i]][team1[j]] + board[team1[j]][team1[i]]);
                one += (board[team2[i]][team2[j]] + board[team2[j]][team2[i]]);
            }
        }
        answer = min(answer, abs(zero - one));
        return;
    }

    for (int i = index; i < N; i++)
    {
        visited[i] = true;
        setTeam(i + 1, cnt + 1);
        visited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    answer = INF;
    // index, cnt
    setTeam(0, 0);
    cout << answer << '\n';
    return 0;
}