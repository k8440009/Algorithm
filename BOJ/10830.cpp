// 행렬 제곱
// https://www.acmicpc.net/problem/10830
/*
    Square and Multiply
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 5;
int N, B;
int arr1[MAX][MAX];
int arr2[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> B;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> arr1[i][j];
            arr2[i][j] = arr1[i][j];
        }

    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                arr2[i][j] *= arr1[i][j];
            }
        }
    }

    return 0;
}