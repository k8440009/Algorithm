// 회문
// https://www.acmicpc.net/problem/17609
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N;
string str;
int alpha[26];
bool sudoPalin(int left, int right, bool flag)
{
    if (left > right)
        return true;
    if (str[left] == str[right])
        return sudoPalin(left + 1, right - 1, flag);
    else if (flag)
        return max(sudoPalin(left + 1, right, false), sudoPalin(left, right - 1, false));
    else
        return false;
}
bool palin(string str)
{
    int left = 0, right = str.size() - 1;
    while (left <= right)
    {
        if (str[left] != str[right])
            return false;
        left += 1;
        right -= 1;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        // 회문인 경우
        if (palin(str))
            cout << 0 << '\n';
        // 유사 회문 체크
        else
        {
            // str크기가 홀수인 경우 =>  유사 회문인 경우
            if (sudoPalin(0, str.size() - 1, true))
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }
    }
    return 0;
}

/*
    참고
    https://newdeal123.tistory.com/13
*/