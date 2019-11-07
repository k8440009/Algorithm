// 관중석
// https://www.acmicpc.net/problem/10166
#include <iostream>
using namespace std;
const int MAX = 2000;
bool seat[MAX][MAX + 1];
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    int result = 0;
    int d1, d2;
    cin >> d1 >> d2;

    for (int i = d1; i <= d2; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int g = gcd(i, j);
            int up = j / g, down = i / g;

            if (!seat[up][down])
            {
                seat[up][down] = true;
                result++;
            }
        }
    }

    cout << result << '\n';
}

/*
    참고
    https://www.youtube.com/watch?v=Ym1hpXcA_Eo&t=2s
*/