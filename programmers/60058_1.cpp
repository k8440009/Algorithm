// 괄호 변환
// https://programmers.co.kr/learn/courses/30/lessons/60058
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
string answer = "";
// 균형잡힌 괄호열 위치 반환
int makeSameCnt(string p)
{
    int left = 0, right = 0;
    int index = 0;
    for (char c : p)
    {
        if ((left != 0 && right != 0) && left == right)
            break;
        else
        {
            if (c == '(')
                left += 1;
            else
                right += 1;

            index += 1;
        }
    }
    return index;
}
// 올바른 괄호열 체크
bool correctCheck(string p)
{
    bool flag = true;
    stack<char> st;
    for (char c : p)
    {
        // 비어 있을 때
        if (st.empty())
        {
            if (c == '(')
                st.push(c);
            else
            {
                flag = false;
                return flag;
            }
        }
        // 아닐 때
        else
        {
            if (c == '(')
                st.push(c);
            else
            {
                if (st.top() == '(')
                    st.pop();
                else
                {
                    flag = false;
                    return flag;
                }
            }
        }
    }
    // 비어 있지 않은 경우
    if (!st.empty())
        flag = false;
    return flag;
}

string dfs(string str)
{
    if (str.size() == 0)
        return str;
    else
    {
        string u, v;
        int index = makeSameCnt(str);
        for (int i = 0; i < index; i++)
            u += str[i];
        for (int i = index; i < str.size(); i++)
            v += str[i];
        // 3. u가 올바른 괄호 문자열인 경우
        if (correctCheck(u))
        {
            u += dfs(v);
            return u;
        }
        // 4. u가 올바른 괄호 문자열이 아닌 경우
        else
        {
            string temp = "(";
            temp += dfs(v);
            temp += ")";

            for (int i = 1; i < u.size() - 1; i++)
            {
                if (u[i] == '(')
                    temp += ')';
                else
                    temp += '(';
            }
            return temp;
        }
    }
}
string solution(string p)
{
    bool flag = true;
    flag = correctCheck(p);
    if (flag)
        answer = p;
    else
        answer = dfs(p);
    return answer;
}