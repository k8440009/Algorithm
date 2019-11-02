// TGN
// https://www.acmicpc.net/problem/5063
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        // 광고 안할 때, 광고 할 때, 광고 비용
        int r, e, c;
        cin >> r >> e >> c;

        // 광고 안 할 때가 더 큰 경우
        if (r > (e - c))
            cout << "do not advertise" << '\n';
        else if (r == (e - c))
            cout << "does not matter" << '\n';
        else
            cout << "advertise" << '\n';
    }

    return 0;
}