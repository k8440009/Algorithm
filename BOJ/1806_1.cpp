// 부분합
// https://www.acmicpc.net/problem/1806
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, S;
vector<int> a;
void init()
{
    cin >> N >> S;
    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int start = 0, end = 0, sum = 0, size = INF;
    bool flag = false;
    while (1)
    {
        if (sum >= S)
        {
            flag = true;
            size = min(size, (end - start));
            sum -= a[start++];
        }
        else if (start >= N || end >= N)
            break;
        else
            sum += a[end++];
    }

    if (flag)
        cout << size;
    else
        cout << 0;
    return 0;
}
/* 
    투 포인터 방식을 사용하여 부분합을 구한다.
    start, end를 이용하여 최소 길이를 출력한다.
*/