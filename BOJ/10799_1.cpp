// 쇠막대기
// https://www.acmicpc.net/problem/10799
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 괄호 입력
    string str = "";
    cin >> str;

    stack<char> st;
    int total = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            st.push(str[i]);
        else
        {
            st.pop();
            // 레이저
            if (str[i - 1] == '(')
                total += st.size();
            // 레이저가 아닌 경우
            else
                total++;
        }
    }

    cout << total << '\n';

    return 0;
}

/*
    참고

    https://hsp1116.tistory.com/29
    
*/