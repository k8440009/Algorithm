// !밑비 급일
// https://www.acmicpc.net/problem/11365
#include <iostream>
#include <string>
using namespace std;
string board[500];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int index = 0;
    while (true)
    {
        string str;
        getline(cin, str);
        if (str == "END")
            break;
        board[index] = str;
        index += 1;
    }

    for (int i = 0; i < index; i++)
    {
        for (int j = board[i].size() - 1; j >= 0; j--)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}