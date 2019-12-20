// 행렬 제곱
// https://www.acmicpc.net/problem/10830
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix;
const int MAX = 5 + 1;
const int MOD = 1000;
long long N, B;
matrix arr(MAX, vector<int>(MAX));
matrix DivConq(long long n)
{
    matrix c(N, vector<int>(N));
    matrix a(N, vector<int>(N));

    if (n == 1)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                c[i][j] = arr[i][j] % MOD;
        return c;
    }

    if (n % 2)
    {
        a = DivConq(n - 1);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    c[i][j] += a[i][k] * arr[k][j];
                }

                c[i][j] %= MOD;
            }
        }
    }
    else
    {
        a = DivConq(n / 2);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    c[i][j] += a[i][k] * a[k][j];
                }

                c[i][j] %= MOD;
            }
        }
    }

    return c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> B;

    matrix answer(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    answer = DivConq(B);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
/*
    참고
    https://www.acmicpc.net/problem/10830
    https://dongyeollee.github.io/2018/07/21/Al/10830/
*/