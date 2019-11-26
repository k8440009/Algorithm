// 진짜 메세지
// https://www.acmicpc.net/problem/9324
#include <iostream>
#include <string>
using namespace std;
int alpha[27];
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        fill_n(alpha, 27, 0);
        bool check = true;
        for (int j = 0; j < str.size(); j++)
        {
            int now = str[j] - 'A';
            alpha[now]++;
            if (alpha[now] == 3)
            {
                // 문자열 끝이거나, 다음 인덱스가 다른 문자일 경우
                if (j == str.size() - 1 || str[j] != str[j + 1])
                {
                    check = false;
                    break;
                }
                j++;
                alpha[now] = 0;
            }
        }
        if (check)
            cout << "OK" << '\n';
        else
            cout << "FAKE" << '\n';
    }
}