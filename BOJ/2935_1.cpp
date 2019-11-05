// 소음
// https://www.acmicpc.net/problem/2935
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b, answer = "";
    char c;
    cin >> a >> c >> b;
    // 1. 덧셈인 경우
    if (c == '+')
    {
        // a가 큰 경우
        if (a.size() > b.size())
        {
            answer = a;
            int index = a.size() - b.size();
            answer[index] = '1';
        }
        // b가 큰 경우
        else if (a.size() < b.size())
        {
            answer = b;
            int index = b.size() - a.size();
            answer[index] = '1';
        }
        // 같은 경우
        else
        {
            answer = b;
            answer[0] = '2';
        }
    }
    // 2. 곱셈인 경우
    else
    {
        // 맨 앞에 숫자 1과 영의 갯수만큼 0 출력
        int length = a.size() - 1 + b.size() - 1;
        answer = "1";
        for (int i = 0; i < length; i++)
            answer += "0";
    }

    cout << answer << '\n';

    return 0;
}
/*
    참고
    https://jaimemin.tistory.com/960
*/