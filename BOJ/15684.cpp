// 사다리 조작
// https://www.acmicpc.net/problem/15684
#include <bits/stdc++.h>
using namespace std;
int N, M, H;
bool board[11][31];
bool visited[11][31];
vector<pair<int, int>> line;
int answer;
bool search()
{
    for (int i = 1; i <= N; i++)
    {
        int current = i;
        for (int j = 1; j <= H; j++)
        {
            if (visited[current][j])
                current += 1;
            else if (visited[current - 1][j])
                current -= 1;
        }

        if (current != i)
            return false;
    }
    return true;
}
void dfs(int index, int cnt)
{
    if (cnt >= 4)
        return;

    if (search())
    {
        answer = min(answer, cnt);
        return;
    }

    for (int r = index; r <= H; r++)
    {
        for (int c = 1; c < N; c++)
        {
            if (visited[c][r])
                continue;
            if (visited[c - 1][r])
                continue;
            if (visited[c + 1][r])
                continue;

            visited[c][r] = true;
            dfs(r, cnt + 1);
            visited[c][r] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> H;

    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        visited[b][a] = true;
    }

    answer = 987654321;
    dfs(1, 0);
    if (answer == 987654321)
        answer = -1;
    cout << answer << '\n';
    return 0;
}