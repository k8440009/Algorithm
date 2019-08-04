#include <bits/stdc++.h>
using namespace std;
#define MAX 10
const int INF = 987654321;
int w[MAX][MAX];
// next_permutaion O(N * N!)
void solve1()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        d[i] = i;
    }

    int answer = INF;
    do
    {
        bool ok = true;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int here = d[i];
            int next = d[i + 1];

            if (w[here][next] == 0)
            {
                ok = false;
                break;
            }

            else
                sum += w[here][next];
        }

        int start = d[0];
        int last = d[n - 1];
        // 0을 안 지나고, 마지막으로 가는 길이 0이 아닌경우
        if (ok && w[last][start] != 0)
        {
            sum += w[last][start];

            if (answer > sum)
                answer = sum;
        }
    } while (next_permutation(d.begin(), d.end()));

    cout << answer << '\n';
}
// 시작점 고정O(N!)
void solve2()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        d[i] = i;
    }

    int answer = INF;
    do
    {
        bool ok = true;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int here = d[i];
            int next = d[i + 1];

            if (w[here][next] == 0)
            {
                ok = false;
                break;
            }

            else
                sum += w[here][next];
        }

        int start = d[0];
        int last = d[n - 1];
        // 0을 안 지나고, 마지막으로 가는 길이 0이 아닌경우
        if (ok && w[last][start] != 0)
        {
            sum += w[last][start];

            if (answer > sum)
                answer = sum;
        }
    } while (next_permutation(d.begin() + 1, d.end()));

    cout << answer << '\n';
}
int main()
{

    solve1(); // O(N * N!);
    solve2(); // O(N!)
    return 0;
}