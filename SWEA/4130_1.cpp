// 4130 [모의 SW 역량테스트] 특이한 자석
#include <iostream>
#include <vector>
using namespace std;
int k;
int gear[4][8];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> k;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 8; j++)
                cin >> gear[i][j];
        for (int i = 0; i < k; i++)
        {
            int target, cmd;
            cin >> target >> cmd;
            target -= 1;

            int moving[4];
            fill_n(moving, 4, 0);
            moving[target] = cmd;

            for (int left = target - 1; left >= 0; left--)
            {
                int right = left + 1;
                if (gear[left][2] == gear[right][6])
                    break;
                else
                    moving[left] = moving[right] * -1;
            }

            for (int right = target + 1; right < 4; right++)
            {
                int left = right - 1;
                if (gear[left][2] == gear[right][6])
                    break;
                else
                    moving[right] = moving[left] * -1;
            }

            for (int j = 0; j < 4; j++)
            {
                if (moving[j] == 1)
                {
                    int temp = gear[j][7];
                    for (int k = 7; k - 1 >= 0; k--)
                    {
                        gear[j][k] = gear[j][k - 1];
                    }
                    gear[j][0] = temp;
                }
                else if (moving[j] == -1)
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
        cout << "#" << ts << ' ' << answer << '\n';
    }
    return 0;
}
