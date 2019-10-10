// 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
int N, M, answer = 987654321;
int board[MAX][MAX];
int copyBoard[MAX][MAX];
vector<pair<int, int>> chicken, pick;
void calculate()
{
    int dist = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (board[y][x] == 1)
            {
                int temp = 987654321;
                for (int i = 0; i < pick.size(); i++)
                {
                    temp = min(temp, abs(pick[i].first - y) + abs(pick[i].second - x));
                }
                dist += temp;
            }
        }
    }

    answer = min(answer, dist);
}
void dfs(int index, int cnt)
{
    if (cnt == M)
    {
        calculate();
        return;
    }

    for (int i = index; i < chicken.size(); i++)
    {
        pick.push_back(make_pair(chicken[i].first, chicken[i].second));
        dfs(i + 1, cnt + 1);
        pick.pop_back();
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
            if (board[y][x] == 2)
            {
                chicken.push_back(make_pair(y, x));
            }
        }
    }

    // 치킨집 갯수, r,c
    dfs(0, 0);

    cout << answer << '\n';
    return 0;
}