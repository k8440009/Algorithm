// 쿼드 트리
// https://www.acmicpc.net/problem/1992
#include <iostream>
#include <string>
using namespace std;
const int MAX = 64;
int N;
int board[MAX][MAX];
string str = "";
bool check(int sy, int sx, int n)
{
    for (int y = sy; y < sy + n; y++)
        for (int x = sx; x < sx + n; x++)
            if (board[y][x] != board[sy][sx])
                return false;
    return true;
}
void div_conq(int sy, int sx, int n)
{
    // 기저 사례
    if (n == 1)
    {
        if (board[sy][sx] == 0)
            str += "0";
        else
            str += "1";
        return;
    }

    // 분할
    bool flag = check(sy, sx, n);
    // 병합
    if (flag)
    {
        if (board[sy][sx] == 0)
            str += "0";
        else
            str += "1";
    }
    else
    {
        str += "(";
        int size = n / 2;
        div_conq(sy, sx, size);
        div_conq(sy, sx + size, size);
        div_conq(sy + size, sx, size);
        div_conq(sy + size, sx + size, size);
        str += ")";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int y = 0; y < N; y++)
    {

        string str;
        cin >> str;
        for (int x = 0; x < N; x++)
        {
            board[y][x] = str[x] - '0';
        }
    }

    div_conq(0, 0, N);

    cout << str << '\n';
}