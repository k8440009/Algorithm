// 균형잡힌 세상
// https://www.acmicpc.net/problem/4949
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        string str;
        getline(cin, str);
        stack<char> st;

        if (str[0] == '.' && str.length() == 1)
            break;

        bool check = true;
        for (auto c : str)
        {
            if (c == '(')
                st.push(c);
            else if (c == '[')
                st.push(c);
            else if (c == ')')
            {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                {
                    check = false;
                    break;
                }
            }
            else if (c == ']')
            {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                {
                    check = false;
                    break;
                }
            }
        }

        if (check && st.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}
