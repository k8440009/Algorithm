// 1213. [S/W 문제해결 기본] 3일차 - String
#include <iostream>
#include <string>
using namespace std;
int tc;
string a, b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    while (1)
    {
        cin >> tc >> a >> b;
        int cnt = 0;
        int len = a.size();
        for (int i = 0; i <= b.size() - len; i++)
        {
            if (a == b.substr(i, a.size()))
                cnt++;
        }
        cout << "#" << tc << ' ' << cnt << '\n';

        if (tc == 10)
            break;
    }

    return 0;
}
/*
    참고
    https://blockdmask.tistory.com/338
*/