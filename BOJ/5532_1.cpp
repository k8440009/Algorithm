// 방학 숙제
// https://www.acmicpc.net/problem/5532
#include <iostream>
#include <algorithm>
using namespace std;
int L, A, B, C, D;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 방학, 국어, 수학 , 하루 국어, 하루 수학
    cin >> L >> A >> B >> C >> D;
    int language = A / C;
    int math = B / D;
    if (A % C != 0)
        language += 1;
    if (B % D != 0)
        math += 1;

    cout << L - max(language, math) << '\n';
    return 0;
}