// 스타트와 링크
// https://www.acmicpc.net/problem/14889
#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
int N;
int board[MAX][MAX];
bool visited[MAX];
int answer = 987654321;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 0. 입력
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    // 1. 뽑기
    vector<int> check(N);
    for (int i = 0; i < N / 2; i++)
        check[i] = 1;

    sort(check.begin(), check.end());
    do
    {
        vector<int> start, link;
        for (int i = 0; i < N; i++)
        {
            // 스타트팀
            if (check[i] == 0)
                start.push_back(i);
            // 링크 팀
            else
                link.push_back(i);
        }

        int startTeam = 0;
        int linkTeam = 0;

        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                if (i == j)
                    continue;
                startTeam += board[start[i]][start[j]];
                linkTeam += board[link[i]][link[j]];
            }
        }
        answer = min(answer, abs(startTeam - linkTeam));
    } while (next_permutation(check.begin(), check.end()));
    cout << answer << '\n';
    return 0;
}