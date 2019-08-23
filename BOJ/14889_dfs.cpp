// 스타트와 링크
// https://www.acmicpc.net/problem/14889
#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
int n;
int board[MAX][MAX];
bool visited[MAX];
int answer = 987654321;
void dfs(int index, int cnt)
{
    // n/2를 뽑았을 때
    if (cnt == n / 2)
    {
        vector<int> start, link;
        for (int i = 0; i < n; i++)
        {
            // 스타트팀
            if (visited[i] == 0)
                start.push_back(i);
            // 링크 팀
            else
                link.push_back(i);
        }

        int startTeam = 0;
        int linkTeam = 0;

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (i == j)
                    continue;
                startTeam += board[start[i]][start[j]];
                linkTeam += board[link[i]][link[j]];
            }
        }
        answer = min(answer, abs(startTeam - linkTeam));
    }

    for (int i = index; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        dfs(i + 1, cnt + 1);
        visited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    dfs(0, 0);

    cout << answer << '\n';
    return 0;
}