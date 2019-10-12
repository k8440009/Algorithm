// 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
int N, M, answer = 987654321;
int board[MAX][MAX];
vector<pair<int, int>> house, chicken;
bool selected[13];
void dfs(int index, int cnt)
{
    if (cnt == M)
    {
        int total = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int dist = 987654321;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (selected[j])
                {
                    dist = min(dist, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
                }
            }
            total += dist;
        }
        answer = min(answer, total);
        return;
    }

    for (int i = index; i < chicken.size(); i++)
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

    cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == 1)
                house.push_back(make_pair(y, x));
            else if (board[y][x] == 2)
                chicken.push_back(make_pair(y, x));
        }
    }
    dfs(0, 0);
    cout << answer << '\n';
    return 0;
}