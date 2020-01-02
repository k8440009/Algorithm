// 1208. [S/W 문제해결 기본] 1일차 - Flatten
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int dump;
int height[100];
struct status
{
    int min, minIndex, max, maxIndex;
};
status minMax;
void findMinMax()
{
    for (int i = 0; i < 100; i++)
    {
        if (i == 0)
            minMax.max = height[i], minMax.min = height[i], minMax.maxIndex = i, minMax.minIndex = i;
        else
        {
            // 최대
            if (height[i] > minMax.max)
            {
                minMax.max = height[i];
                minMax.maxIndex = i;
            }
            // 최소
            if (height[i] < minMax.min)
            {
                minMax.min = height[i];
                minMax.minIndex = i;
            }
        }
    }
}
int solve()
{
    int cnt = 0;
    cnt += 1;
    for (int cnt = 0; cnt < dump; cnt++)
    {
        // 최대 최소 찾음
        findMinMax();
        height[minMax.maxIndex]--;
        height[minMax.minIndex]++;
    }
    findMinMax();
    return minMax.max - minMax.min;
}
void init()
{
    cin >> dump;
    for (int i = 0; i < 100; i++)
        cin >> height[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    for (int ts = 1; ts <= 10; ts++)
    {
        init();
        cout << "#" << ts << ' ' << solve() << '\n';
    }

    return 0;
}