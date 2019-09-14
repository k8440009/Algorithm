// 2058. 자릿수 더하기
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number;
    cin >> number;
    int answer = 0;

    while (number > 0)
    {
        answer += number % 10;
        number = number / 10;
    }

    cout << answer << '\n';
    return 0;
}