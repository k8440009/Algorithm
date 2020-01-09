// 에라토스테네스의 체
//https://www.acmicpc.net/problem/2960
#include <iostream>
using namespace std;
const int MAX = 1000 + 1;
int N, K;
bool board[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    fill_n(board, MAX, true);

    int cnt = 0;
    for (int i = 2; i <= N; i++)
    {
        // 지워지지 않은 작은 수
        if (board[i])
        {
            // 배수
            for (int j = i; j <= N; j += i)
            {
                // 지워지지 않았으면 지우고 갯수 증가
                if (board[j])
                {
                    board[j] = false;
                    cnt += 1;
                }
                // K번째 지워진 수
                if (cnt == K)
                {
                    cout << j << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}
