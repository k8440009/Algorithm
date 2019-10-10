// 요리사
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 16;
const int INF = 987654321;
int T, N, answer;
int board[MAX][MAX];
bool selected[MAX];
void dfs(int index, int cnt)
{
    if (cnt == N / 2)
    {
        vector<int> a(N / 2), b(N / 2);
        int aIndex = 0, bIndex = 0;
        for (int i = 0; i < N; i++)
        {
            if (selected[i])
            {
                a[aIndex] = i;
                aIndex += 1;
            }
            else
            {
                b[bIndex] = i;
                bIndex += 1;
            }
        }

        int zero = 0, one = 0;
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = i + 1; j < N / 2; j++)
            {
                zero += (board[a[i]][a[j]] + board[a[j]][a[i]]);
                one += (board[b[i]][b[j]] + board[b[j]][b[i]]);
            }
        }

        answer = min(answer, abs(zero - one));
        return;
    }

    for (int i = index; i < N; i++)
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

    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        answer = INF;
        cin >> N;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                cin >> board[y][x];
            }
        }

        dfs(0, 0);

        cout << "#" << tc << ' ' << answer << '\n';
    }
    return 0;
}