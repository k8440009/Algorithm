// 세로읽기
// https://www.acmicpc.net/problem/10798
#include <iostream>
#include <string>
using namespace std;
const int MAX = 15;
string board[5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str = "";
    for (int i = 0; i < 5; i++)
        cin >> board[i];

    // 세로로 접근
    for (int x = 0; x < MAX; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            // 공백
            /*
            if (board[y][x] == ' ')
                continue;
            */
            // null
            if (board[y][x] == '\0')
                continue;
            // 순서대로 출력
            else
                str += board[y][x];
        }
    }

    cout << str << '\n';
}