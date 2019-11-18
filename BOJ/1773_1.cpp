// 폭죽쇼
// https://www.acmicpc.net/problem/1773
#include <iostream>
using namespace std;
const int MAX = 2000000 + 1;
int N, C;
bool check[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int bomb, answer = 0;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> bomb;
        if (check[bomb]) // 중복 된 경우는 방문 할 필요 없음
            continue;
        for (int j = 1; j * bomb <= C; j++)
            if (!check[j * bomb])
            {
                check[j * bomb] = true;
                answer++;
            }
    }

    cout << answer;

    return 0;
}