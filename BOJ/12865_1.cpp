// 평범한 배낭
// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    참고
    https://naivep.tistory.com/71
    https://naivep.tistory.com/72
    https://hibee.tistory.com/235
*/

const int MAX = 100000 + 1;
int N, K;

int dp[101][MAX];
int weight[101];
int value[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> weight[i] >> value[i];

    // 1 ~ 모든 물체 갯수
    for (int i = 1; i <= N; i++)
    {
        // 0 ~ 배낭 무게 까지
        for (int j = 0; j <= K; j++)
        {
            dp[i][j] = dp[i - 1][j]; // 이전 무게의 가치를 저장
            // i번째 물체의 무게와 j를 비교
            if (j - weight[i] >= 0)
            {
                // 이전 무게의 가치와 새로 넣는 아이템의 가치를 비교하여 최대값을 구한다.
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[N][K] << '\n';
    return 0;
}
