// 골드바흐의 추측
// https://www.acmicpc.net/problem/6588
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000 + 1;
int N, K;
bool board[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 체
    fill_n(board, MAX, true); // 소수만 true
    for (int i = 2; i <= MAX; i++)
    {
        // 지워지지 않은 작은 수
        if (board[i])
        {
            // 배수
            for (int j = i + i; j <= MAX; j += i)
            {
                // 지워지지 않았으면 지우고 갯수 증가
                if (board[j])
                    board[j] = false;
            }
        }
    }

    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
            break;
        bool flag = false;
        for (int i = 3; i <= N; i += 2)
        {
            int diff = N - i;
            if (board[i] && board[diff])
            {
                flag = true;
                cout << N << " = " << i << " + " << diff << '\n';
                break;
            }
        }

        if (!flag)
            cout << "Goldbach's conjecture is wrong" << '\n';
    }

    return 0;
}
