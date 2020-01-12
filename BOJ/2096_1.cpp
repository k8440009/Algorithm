// 내려가기
// https://www.acmicpc.net/problem/2096
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, colMax[3], colMin[3], // 이전 행 배열
    tempMax[3], tempMin[3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> tempMax[j];
            tempMin[j] = tempMax[j];
            if (j == 0)
            {
                tempMax[0] += max(colMax[0], colMax[1]);
                tempMin[0] += min(colMin[0], colMin[1]);
            }
            else if (j == 1)
            {
                tempMax[1] += max(colMax[0], max(colMax[1], colMax[2]));
                tempMin[1] += min(colMin[0], min(colMin[1], colMin[2]));
            }
            else
            {
                tempMax[2] += max(colMax[1], colMax[2]);
                tempMin[2] += min(colMin[1], colMin[2]);
            }
        }

        for (int j = 0; j < 3; j++)
            colMax[j] = tempMax[j], colMin[j] = tempMin[j];
    }

    sort(colMin, colMin + 3);
    sort(colMax, colMax + 3);

    cout << colMax[2] << ' ' << colMin[0];
    return 0;
}

/*
    int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> tempMax[j];
            tempMin[j] = tempMax[j];
            tempMax[j] += max(colMax[1], (j == 1) ? max(colMax[0], colMax[2]) : colMax[j]);
            tempMin[j] += min(colMin[1], (j == 1) ? min(colMin[0], colMin[2]) : colMin[j]);
        }

        
        // colMax, colMin 배열을 temp 배열로 덮어쓰기하여 다음 루프에서 사용
        memcpy(colMax, tempMax, sizeof(int) * 3);
        memcpy(colMin, tempMin, sizeof(int) * 3);
        

        for (int j = 0; j < 3; j++)
            colMax[j] = tempMax[j], colMin[j] = tempMin[j];
    }
    sort(colMin, colMin + 3);
    sort(colMax, colMax + 3);
    cout << colMax[2] << ' ' << colMin[0];
    return 0;
}
*/

/*
    참조
    https://kks227.blog.me/
*/