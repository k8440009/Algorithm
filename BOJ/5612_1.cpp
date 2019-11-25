// 터널의 입구와 출구
// https://www.acmicpc.net/problem/5612
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int tunul = M, temp = M;
    for (int i = 1; i <= N; i++)
    {
        int start, end;
        cin >> start >> end;
        temp += (start - end);
        if (temp < 0)
        {
            cout << 0;
            return 0;
        }
        tunul = max(tunul, temp);
    }
    cout << tunul;
    return 0;
}