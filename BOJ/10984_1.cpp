// 내 학점을 구해줘
// https://www.acmicpc.net/problem/10984
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc, n;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> n;

        double hac = 0, score = 0;
        for (int i = 0; i < n; i++)
        {
            double a, b;
            cin >> a >> b;
            hac += a, score += (a * b);
        }

        cout << (int)hac << ' ';
        cout.precision(1);
        cout.setf(ios::fixed, ios::floatfield); // 형식 지정
        cout << score / hac << '\n';
    }

    return 0;
}
/*
    참고
    https://jaimemin.tistory.com/958
    https://codecollector.tistory.com/455
    https://kcoder.tistory.com/entry/C-cout-%EC%9D%98-%EB%AA%A8%EB%93%A0-%EA%B2%83-%EC%82%AC%EC%9A%A9%EB%B2%95-%EC%86%8C%EC%88%98%EC%A0%90-%EC%B6%9C%EB%A0%A5%EC%96%91%EC%8B%9D
*/