// 괄호 추가하기
// https://acmicpc.net/problem/16637
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 19 + 1;
const int INF = 987654321;
int N, answer = -INF;
int num[MAX];
char opr[MAX];
int calculate(int a, int b, char opr)
{
    if (opr == '+')
        return a + b;
    else if (opr == '-')
        return a - b;
    else if (opr == '*')
        return a * b;
}
void dfs(int index, int result)
{
    if (index >= N / 2)
    {
        answer = max(answer, result);
        return;
    }

    int cur = calculate(result, num[index + 1], opr[index]);
    dfs(index + 1, cur);

    if (index + 1 < N / 2)
    {
        int after = calculate(num[index + 1], num[index + 2], opr[index + 1]);
        int cur = calculate(result, after, opr[index]);
        dfs(index + 2, cur);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> N >> str;

    int index1 = 0, index2 = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (i % 2 == 0)
            num[index1++] = str[i] - '0';
        else
            opr[index2++] = str[i];
    }

    if (N == 1)
        cout << num[0] << '\n';
    else if (N == 3)
        cout << calculate(num[0], num[1], opr[0]) << '\n';
    else
    {
        dfs(0, num[0]);
        cout << answer << '\n';
    }
    return 0;
}