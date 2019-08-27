// 맞춰봐
// https://www.acmicpc.net/problem/1248
#include <bits/stdc++.h>
using namespace std;
int buho[10][10];
vector<int> answer;
int n;

int main()
{
    cin >> n;
    answer.resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '0')
                buho[i][j] = 0;
            if (c == '+')
                buho[i][j] = 1;
            if (c == '-')
                buho[i][j] = -1;
        }
    }
    return 0;
}
