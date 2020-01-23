// 수열
// https://www.acmicpc.net/problem/2559
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 9987654321;
const int MAX = 100000 + 1;
int N, K;
int temper[MAX];
void init()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> temper[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int sum = 0, answer = -INF;
    int start = 0, end = 0;
    while (true)
    {
        if (end - start != K)
        {
            sum += temper[end++];
        }
        else
        {
            answer = max(answer, sum);
            sum -= temper[start++];
        }

        if (end == N + 1)
            break;
    }

    cout << answer;
    return 0;
}