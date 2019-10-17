// 톱니 바퀴
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
        {
            gear[i][j] = str[j] - '0';
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int target, cmd;
        cin >> target >> cmd;
        target -= 1;

        int moveGear[4];
        // 0 : 안돌림, 1 : 시계, -1 : 반시계
        fill_n(moveGear, 4, 0);
        moveGear[target] = cmd;
        // 돌릴 것들 예정
        for (int left = target - 1; left >= 0; left--)
        {
            int right = left + 1;
            if (gear[left][2] == gear[right][6])
                break;
            else
            {
                moveGear[left] = moveGear[right] * -1;
            }
        }
        for (int right = target + 1; right < 4; right++)
        {
            int left = right - 1;
            if (gear[left][2] == gear[right][6])
                break;
            else
            {
                moveGear[right] = moveGear[left] * -1;
            }
        }
        // 돌리기
        for (int j = 0; j < 4; j++)
        {
            if (moveGear[j] == -1)
            {
                int temp = gear[j][0];
                for (int k = 0; k + 1 < 8; k++)
                {
                    gear[j][k] = gear[j][k + 1];
                }
                gear[j][7] = temp;
            }
            else if (moveGear[j] == 1)
            {
                int temp = gear[j][7];
                for (int k = 7; k - 1 >= 0; k--)
                {
                    gear[j][k] = gear[j][k - 1];
                }
                gear[j][0] = temp;
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
