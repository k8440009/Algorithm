// 종이의 갯수
// https://www.acmicpc.net/problem/1780
#include <iostream>
using namespace std;
const int MAX = 2187 + 1;
int board[MAX][MAX];
int N;
int answer[3];

void paper(int sy, int sx, int n);
bool check(int sy, int sx, int n);

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];
    paper(0, 0, N);
    for (int i = 0; i < 3; i++)
    {
        cout << answer[i] << '\n'; // -1,0,1
    }
}

void paper(int sy, int sx, int n)
{
    // 기저사례
    if (n == 1)
    {
        if (board[sy][sx] == -1)
            answer[0]++;
        else if (board[sy][sx] == 0)
            answer[1]++;
        else
            answer[2]++;
        return;
    }

    int cri = board[sy][sx];
    bool flag = check(sy, sx, n);
    // 분할
    if (flag)
    {
        if (board[sy][sx] == -1)
            answer[0]++;
        else if (board[sy][sx] == 0)
            answer[1]++;
        else
            answer[2]++;
    }
    else
    {
        int size = n / 3;
        paper(sy, sx, size);
        paper(sy, sx + size, size);
        paper(sy, sx + size * 2, size);

        paper(sy + size, sx, size);
        paper(sy + size, sx + size, size);
        paper(sy + size, sx + size * 2, size);

        paper(sy + size * 2, sx, size);
        paper(sy + size * 2, sx + size, size);
        paper(sy + size * 2, sx + size * 2, size);
    }

    return;
}

bool check(int sy, int sx, int n)
{
    int criteria = board[sy][sx];

    for (int y = sy; y < sy + n; y++)
        for (int x = sx; x < sx + n; x++)
            if (board[y][x] != criteria)
                return false;
    return true;
}