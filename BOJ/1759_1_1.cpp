// 암호 만들기
// https://www.acmicpc.net/problem/1759
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<char> alpa;
// 최소 1개 모음, 최소 2개 자음
// 인덱스, 암호, 길이
bool check(string &password)
{
    int a = 0; // 모음
    int b = 0; // 자음
    for (char c : password)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            a += 1;
        else
            b += 1;
    }
    return a >= 1 && b >= 2;
}
// 인덱스, 비밀번호, 목표
void recursive(int index, string password, int l)
{
    if (password.length() == l)
    {
        if (check(password))
            cout << password << '\n';

        return;
    }
    if (index == alpa.size())
        return;
    recursive(index + 1, password + alpa[index], l);
    recursive(index + 1, password, l);
}
int main()
{
    int l, c;
    cin >> l >> c; // 암호 길이, 문자들
    alpa.resize(c);
    for (int i = 0; i < c; i++)
        cin >> alpa[i];
    sort(alpa.begin(), alpa.end());
    recursive(0, "", l);
    return 0;
}