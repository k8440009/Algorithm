// 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659
#include <iostream>
using namespace std;
const int MAX = 100000 + 1;
int N, M;
int num[MAX];
int cache[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> num[i];

    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += num[i];
        cache[i] = sum;
    }

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << cache[b] - cache[a - 1] << '\n';
    }
    return 0;
}
