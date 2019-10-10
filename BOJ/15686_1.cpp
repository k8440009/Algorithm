// 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
const int INF = 987654321;
int N, M;
int result;
int board[MAX][MAX];
bool visited[13]; // 치킨집 갯수는 최대 13개
vector<pair<int, int>> house, chicken;
int distance(pair<int, int> &a, pair<int, int> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void dfs(int index, int selected)
{
    // 치킨집 M개 선택
    if (selected == M)
    {
        int temp = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int dist = INF;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (visited[j])
                    dist = min(dist, distance(house[i], chicken[j]));
            }

            temp += dist;
        }
        result = min(result, temp);
        return;
    }
    // 기저 사례
    // index가 chicken집 갯수와 같을 때
    if (index == chicken.size())
        return;

    visited[index] = true;
    // 치킨 집을 선택 한 경우
    dfs(index + 1, selected + 1);
    visited[index] = false;
    // 치킨 집을 선택하지 않은 경우
    dfs(index + 1, selected);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            // 집
            if (board[i][j] == 1)
            {
                house.push_back(make_pair(i, j));
            }
            // 치킨 집
            else if (board[i][j] == 2)
            {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    result = INF;
    // house, chicken
    dfs(0, 0);
    cout << result << '\n';
}