// 크로스워드 만들기
// https://www.acmicpc.net/problem/2804
#include <iostream>
#include <string>
using namespace std;
const int MAX = 30;
string A, B;
int sy = 0, sx = 0;
char board[MAX][MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
    // 겹치는 부분
    int sy, sx = 0;
    for (int i = 0; i < A.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < B.size(); j++)
        {
            if (A[i] == B[j])
            {
                sy = i, sx = j;
                flag = true;
                break;
            }
        }

        if (flag)
            break;
    }

    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (j == sy && i != sx)
                cout << B[i];
            else if (i == sx)
                cout << A[j];
            else
                cout << ".";
        }
        cout << '\n';
    }

    return 0;
}
