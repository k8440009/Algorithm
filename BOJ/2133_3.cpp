// 타일 채우기
// https://www.acmicpc.net/problem/2133
#include <iostream>
using namespace std;
const int MAX = 30 + 1;
int N, cache[MAX];
int tiling(int width)
{
    // 기저 사례
    if (width % 2 == 1) // 홀수는 0
        return 0;
    else if (width <= 0)
        return 1;
    else if (width == 2)
        return 3;
    int &ret = cache[width];
    if (ret != -1)
        return ret;
    ret = 3 * tiling(width - 2); // 2 * tiling(width-2)
    // width - 4 부터는 고유 모양을 더해야한다.
    for (int i = width - 4; i >= 0; i -= 2)
        ret += 2 * tiling(i); // 고유모양 2가지 * tiling(i)
    return ret;
}
void init()
{
    cin >> N;
    fill_n(cache, MAX, -1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << tiling(N) << '\n';
    return 0;
}
/*  
    참고
    https://jaimemin.tistory.com/330
*/