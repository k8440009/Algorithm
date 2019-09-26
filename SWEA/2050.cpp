// 2050 알파벳을 숫자로 변환
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    for (int i = 0; i < str[i]; i++)
    {
        cout << str[i] - 'A' + 1 << ' ';
    }
    cout << '\n';
    return 0;
}