// Z
// https://www.acmicpc.net/problem/1074
#include <iostream>
using namespace std;
int N, R, C;
int cnt = 0;
void div_conq(int sy, int sx, int n)
{
    if (sy == R && sx == C)
    {
        cout << cnt << '\n';
        return;
    }
    // 시작점의 y or x에서 n이상 벗어나는 경우, 사각형안에 없는 경우
    if ((sy > R || sy + n <= R) || (sx > C || sx + n <= C))
    {
        cnt += (n * n);
        return;
    }

    int size = n / 2; // n /2
    div_conq(sy, sx, size);
    div_conq(sy, sx + size, size);
    div_conq(sy + size, sx, size);
    div_conq(sy + size, sx + size, size);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> C;
    div_conq(0, 0, 1 << N);
    return 0;
}

/*
    참고
    https://mygumi.tistory.com/284
*/