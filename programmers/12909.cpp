// 올바른 괄호
// https://programmers.co.kr/learn/courses/30/lessons/12909
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')' && !st.empty())
            st.pop();
        else
        {
            answer = false;
            break;
        }
    }

    if (!st.empty())
        answer = false;

    return answer;
}