// 2×n 타일링 2
// https://www.acmicpc.net/problem/11727
#include <iostream>
using namespace std;
const int MAX = 1000 + 1, MOD = 10007;
int N, cache[MAX];
// 2* width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지 반환
int tiling(int width)
{
    // 기저 사례
    if (width <= 1)
        return 1;

    int &ret = cache[width];

    if (ret != -1)
        return ret;

    return ret = (tiling(width - 1) + 2 * tiling(width - 2)) % MOD;
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