// 톱니바퀴
// https://www.acmicpc.net/problem/14891
#include <iostream>
#include <string>
using namespace std;
int gear[4][8];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 8; j++)
            gear[i][j] = str[j] - '0';
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int target, cmd;
        cin >> target >> cmd;
        target -= 1;

        int move[4];
        fill_n(move, 4, 0);
        move[target] = cmd;
        // left
        for (int left = target - 1; left >= 0; left--)
        {
            int right = left + 1;
            if (gear[left][2] == gear[right][6])
                break;
            else
                move[left] = move[right] * -1;
        }
        // 오른쪽
        for (int right = target + 1; right < 4; right++)
        {
            int left = right - 1;
            if (gear[left][2] == gear[right][6])
                break;
            else
                move[right] = move[left] * -1;
        }
        // 움직임
        for (int j = 0; j < 4; j++)
        {
            // 오른쪽
            if (move[j] == 1)
            {
                int temp = gear[j][7];
                for (int k = 7; k - 1 >= 0; k--)
                {
                    gear[j][k] = gear[j][k - 1];
                }
                gear[j][0] = temp;
            }
            else if (move[j] == -1)
            {
                int temp = gear[j][0];
                for (int k = 0; k + 1 <= 7; k++)
                {
                    gear[j][k] = gear[j][k + 1];
                }
                gear[j][7] = temp;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 4; i++)
    {
        if (gear[i][0] == 1)
            answer += (1 << i);
    }

    cout << answer << '\n';
    return 0;
}
