// 2115. [모의 SW 역량테스트] 벌꿀채취
/*
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, C;
const int MAX = 10 + 1;
int board[MAX][MAX];
bool visited[MAX][MAX];
// A선택
void dfs(int y, int x)
{
    for (int cnt = 0; cnt < M; cnt++)
    {
        visited[y][x + cnt] = true;
    }

    for (int y = 0; y < N; y++)
    {
        int cnt = 0;
        for (int x = 0; x < N; x++)
        {
            if (visited[y][x])
                continue;
        }
        if(cnt != M){

        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        // 벌통 크기, 벌통 갯수, 꿀의 양
        cin >> N >> M >> C;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                cin >> board[y][x];
            }
        }
        //
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x <= N - M; x++)
            {
                dfs(y, x);
            }
        }
    }
}
*/