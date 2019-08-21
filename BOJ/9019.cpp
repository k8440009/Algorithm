// DSLR
// https://www.acmicpc.net/problem/9019
#include <bits/stdc++.h>
using namespace std;
char command[4] = {'D', 'S', 'L', 'R'};
const int MAX = 10000 + 1;

bool check[MAX];
int dist[MAX];
char how[MAX];
int from[MAX];

/*
    dslr => string으로 계산하면 시간 초과
*/
void print(int n, int m)
{
    if (n == m)
        return;
    print(n, from[m]);
    cout << how[m];
}
int D(int num)
{
    int number = (num * 2) % 10000;
    return number;
}
int S(int num)
{
    int number = num - 1;
    if (number == -1)
        number = 9999;
    return number;
}
int L(int num)
{
    return (num % 1000) * 10 + num / 1000;
}

int R(int num)
{
    return (num / 10) + (num % 10) * 1000;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        fill_n(check, MAX, false);
        fill_n(dist, MAX, 0);
        fill_n(how, MAX, 0);
        fill_n(from, MAX, 0);

        queue<int> q;
        q.push(n);
        check[n] = true;
        dist[n] = 0;
        from[n] = -1;

        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            int next = D(now);
            if (!check[next])
            {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'D';
            }

            next = S(now);
            if (!check[next])
            {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'S';
            }
            next = L(now);
            if (!check[next])
            {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'L';
            }
            next = R(now);
            if (!check[next])
            {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'R';
            }
        }

        print(n, m);
        cout << '\n';
    }
    return 0;
}