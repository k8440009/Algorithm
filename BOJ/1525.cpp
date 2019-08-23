// 퍼즐
// https://www.acmicpc.net/problem/1525
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 3;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
                temp = 9;
            start = start * 10 + temp;
        }
    }

    // 숫자의 배열로 위치값을 저장
    // 123456789 => dist출력
    queue<int> q;
    map<int, int> dist;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int nowNum = q.front();
        string now = to_string(nowNum);
        q.pop();

        int z = now.find('9');
        int x = z / 3;
        int y = z % 3;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            string next = now;
            swap(next[x * 3 + y], next[nx * 3 + ny]);
            int num = stoi(next);

            if (dist.count(num) == 0)
            {
                dist[num] = dist[nowNum] + 1;
                q.push(num);
            }
        }
    }

    if (dist.count(123456789) == 0)
        cout << -1 << '\n';
    else
        cout << dist[123456789] << '\n';
    return 0;
}