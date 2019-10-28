// 카드2
// https://www.acmicpc.net/problem/2164
#include <iostream>
#include <queue>
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
    while (true)
    {
        if (q.size() == 1)
        {
            cout << q.front() << '\n';
            q.pop();
            return 0;
        }

        // 1. 맨 위 삭제
        q.pop();

        // 2. 맨위 삭제 한것 아래론
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    return 0;
}