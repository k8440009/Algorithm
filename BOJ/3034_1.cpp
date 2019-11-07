// 앵그리 창영
// https://www.acmicpc.net/problem/3034
#include <iostream>
using namespace std;
int N, W, H;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> W >> H;
    int diag = W * W + H * H;
    for (int i = 0; i < N; i++)
    {
        int len;
        cin >> len;

        if (len * len <= diag)
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }

    return 0;
}
/*
    참고
    https://kwanghyuk.tistory.com/126
*/