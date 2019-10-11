// 톱니바퀴
// https://www.acmicpc.net/problem/14891
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int K;
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

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int target, cmd;
        cin >> target >> cmd;
        target -= 1;
        int move[4];
        fill_n(move, 4, 0);
        move[target] = cmd;
        for (int left = target - 1; left >= 0; left--)
        {
            int right = left + 1;
            if (gear[left][2] == gear[right][6])
                break;
            else
                move[left] = move[right] * -1;
        }

        for (int right = target + 1; right < 4; right++)
        {
            int left = right - 1;
            if (gear[left][2] == gear[right][6])
                break;
            else
                move[right] = move[left] * -1;
        }

        for (int i = 0; i < 4; i++)
        {
            // 역방향
            if (move[i] == -1)
            {
                int temp = gear[i][0];
                for (int j = 0; j < 7; j++)
                {
                    gear[i][j] = gear[i][j + 1];
                }
                gear[i][7] = temp;
            }
            // 정방향
            else if (move[i] == 1)
            {
                int temp = gear[i][7];
                for (int j = 7; j >= 1; j--)
                {
                    gear[i][j] = gear[i][j - 1];
                }
                gear[i][0] = temp;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < 4; i++)
    {
        if (gear[i][0] == 1)
        {
            answer += (1 << i);
        }
    }
    cout << answer << '\n';
    return 0;
}