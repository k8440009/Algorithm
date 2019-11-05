#include <iostream>
using namespace std;
int A, B, N, S;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> A >> B >> N >> S;
        // n가치 코인 a개
        // 1가치 코인 b개

        if (N <= S)
        {
            int a = S / N;
            // 클 때
            if (a > A)
            {
                S -= (N * A);

                int b = S / 1;
                if (b > B)
                    cout << "NO" << '\n';
                else
                    cout << "YES" << '\n';
            }
            else
            {
                S -= (N * a);
                int b = S / 1;
                if (b > B)
                    cout << "NO" << '\n';
                else
                    cout << "YES" << '\n';
            }
        }
        else
        {
            int b = S / 1;
            if (b > B)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
        }
    }
}