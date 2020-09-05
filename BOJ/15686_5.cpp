// 치킨 배달
// https://www.acmicpc.net/problem/15686
/* 
    사용 알고리즘 : 퇴각 검색
	1. 치킨집 위치를 벡터에 저장 후 M개를 선택하면서 최솟값을 계산한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50 + 1;
const int INF = 987654321;
int N, M, answer = INF;
int board[MAX][MAX];
bool selected[MAX];
vector<pair<int, int>> chicken, house;
void dfs(int curr, int cnt)
{
    // M개 선택
    if (cnt == M)
    {
        int total = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int result = INF;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (selected[j])
                {
                    int dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                    result = min(result, dist);
                }
            }
            total += result;
        }
        answer = min(answer, total);
    }
    // 퇴각 검색, 조합
    for (int i = curr; i < chicken.size(); i++)
    {
        selected[i] = true;
        dfs(i + 1, cnt + 1);
        selected[i] = false;
    }
}
void solve()
{
    dfs(0, 0);
    cout << answer << '\n';
    return;
}
void init()
{
    cin >> N >> M;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
            // 집
            if (board[y][x] == 1)
                house.push_back(make_pair(y, x));
            // 치킨
            else if (board[y][x] == 2)
                chicken.push_back(make_pair(y, x));
        }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();

    return 0;
}
