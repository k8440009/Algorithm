// 369 (문자열)
// https://www.acmicpc.net/problem/17614
#include <iostream>
#include <string>
using namespace std;
int N, result;
int check(string num)
{
    int cnt = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '3' || num[i] == '6' || num[i] == '9')
            cnt++;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        result += check(to_string(i));
    }

    cout << result << '\n';
    return 0;
}