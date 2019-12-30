// 2047 신문 헤드라인
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
    string answer = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            answer += (str[i] - 32);
        else
            answer += str[i];
    }
    cout << answer;
    return 0;
}