// 1206 [S/W 문제해결 기본] 1일차 - View
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    for (int ts = 1; ts <= 10; ts++)
    {
        int N, answer = 0;
        int board[MAX];
        fill_n(board, MAX, 0);

        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> board[i];

        for (int target = 2; target < N - 2; target++)
        {
            int cnt = 987654321;
            bool flag = true;
            for (int left = target - 1; left >= target - 2; left--)
            {
                int temp = board[target] - board[left];
                if (temp > 0)
                {
                    cnt = min(cnt, temp);
                }
                else
                {
                    flag = false;
                }
            }

            if (flag)
            {
                for (int right = target + 1; right <= target + 2; right++)
                {
                    int temp = board[target] - board[right];
                    if (temp > 0)
                    {
                        cnt = min(cnt, temp);
                    }
                    else
                    {
                        flag = false;
                    }
                }
            }

            if (flag)
            {
                answer += cnt;
            }
        }

        cout << "#" << ts << ' ' << answer << '\n';
    }

    return 0;
}