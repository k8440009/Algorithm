// 3431. 준환이의 운동관리
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        int l, u, x;
        cin >> l >> u >> x;

        cout << "#" << i << ' ';
        // 필요한 운동량 보다 많은 운동
        if (x > u)
            cout << -1 << '\n';
        else if (x < l)
            cout << l - x << '\n';
        else if (x > l && x < u)
            cout << 0 << '\n';
    }
    return 0;
}