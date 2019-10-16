// 인구이동
// https://www.acmicpc.net/problem/16234
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int N, L, R;
int board[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
        }
    }

    int answer = 0;
    bool isUpdate = true;
    while (isUpdate)
    {
        isUpdate = false;
        int status[MAX][MAX] = {
            0,
        };
        int areaIndex = 0;
        int count[25001] = {
            0,
        };
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (status[y][x] == 0)
                {
                }
            }
        }
        return 0;
    }