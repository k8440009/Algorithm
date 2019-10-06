#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20;
const int INF = 987654321;
int N, answer;
int board[MAX][MAX];
void setTeam(int index, int team[])
{
    if (index == N)
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (team[i] == 0)
                cnt += 1;
        }

        if (cnt == N / 2)
        {
            int startTeam = 0, linkTeam = 0;

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (i == j)
                        continue;
                    else if (team[i] == 0 && team[i] == team[j])
                        startTeam += board[i][j];
                    else if (team[i] == 1 && team[i] == team[j])
                        linkTeam += board[i][j];
                }
            }
            answer = min(answer, abs(startTeam - linkTeam));
        }
        return;
    }

    team[index] = 1;
    setTeam(index + 1, team);
    team[index] = 0;
    setTeam(index + 1, team);
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
    int team[MAX];
    setTeam(0, team);

    cout << answer << '\n';
    return 0;
}