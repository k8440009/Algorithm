// 맞춰봐
// https://www.acmicpc.net/problem/1248
#include <bits/stdc++.h>
using namespace std;
int sign[10][10];
vector<int> answer;
int n;
bool check(int index)
{
    int sum = 0;
    for (int i = index; i >= 0; i--)
    {
        sum += answer[i];
        if (sign[i][index] == 0)
        {
            if (sum != 0)
                return false;
        }

        else if (sign[i][index] < 0)
        {
            if (sum >= 0)
                return false;
        }

        else if (sign[i][index] > 0)
        {
            if (sum <= 0)
                return false;
        }
    }

    return true;
}
bool dfs(int index)
{
    if (index == n)
        return true;

    if (sign[index][index] == 0)
    {
        answer[index] = 0;
        return check(index) && dfs(index + 1);
    }

    for (int i = 1; i <= 10; i++)
    {
        answer[index] = sign[index][index] * i;

        if (check(index) && dfs(index + 1))
            return true;
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    answer.resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            char c;
            cin >> c;
            // sign[i][i] 는 i번째 부호
            if (c == '0')
                sign[i][j] = 0;
            if (c == '+')
                sign[i][j] = 1;
            if (c == '-')
                sign[i][j] = -1;
        }
    }

    dfs(0);
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    return 0;
}
