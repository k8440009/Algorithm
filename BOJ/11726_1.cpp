// 2×n 타일링
// https://www.acmicpc.net/problem/11726
#include <iostream>
using namespace std;
const int MAX = 1000 + 1;
const int MOD = 10007;
int N;
int cache[MAX];
// 2* width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지 반환
int tiling(int width)
{
    // 기저 사례 : width가 1 이하 일때
    if (width <= 1)
        return 1;
    int &ret = cache[width];
    if (ret != -1)
        return ret;
    return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}
void init()
{
    fill_n(cache, MAX, -1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    init();
    cout << tiling(N) << '\n';
    return 0;
}