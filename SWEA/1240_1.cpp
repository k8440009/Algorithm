// 단순 2진 암호 코드
#include <iostream>
using namespace std;
int TC, N, M, HashTable[7000];
char board[50][100];
// board에서 암호코드를 찾아서 반환한다.
int parsing(int row, int col)
{

    int key = 0;
    int cnt = 1;
    for (int i = 0; i < 7; i++)
    {
        if (col < M - 1 && board[row][col + i] == board[row][col + i + 1])
            cnt++;
        else
        {
            key *= 10;
            key += cnt;
            cnt = 1;
        }
    }
    return HashTable[key]; // 해시 테이블 값 return
}
int solve()
{
    int code[8], sum = 0;
    // 암호 코드를 찾는다.
    for (int r = 0; r < N; r++)
    {
        // 암호코드는 최대 56자리
        for (int c = M - 1; c >= 55; c--)
        {
            if (board[r][c] == '1')
            {
                bool flag = true;
                for (int index = 0; index < 8; index++)
                {
                    code[index] = parsing(r, c - 55 + index * 7);
                    if (code[index] < 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
    }

    int odd = code[0] + code[2] + code[4] + code[6];
    int even = code[1] + code[3] + code[5];
    // 올바른 암호코드 인 경우 합을 더한다.
    if ((odd * 3 + even + code[7]) % 10 == 0)
        for (int i = 0; i < 8; i++)
            sum += code[i];
    return sum;
}
void init()
{
    cin >> N >> M;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> board[y][x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    cin >> TC;
    // 해시
    fill_n(HashTable, 7000, -1);
    HashTable[3211] = 0, HashTable[2221] = 1, HashTable[2122] = 2, HashTable[1411] = 3,
    HashTable[1132] = 4, HashTable[1231] = 5, HashTable[1114] = 6, HashTable[1312] = 7,
    HashTable[1213] = 8, HashTable[3112] = 9;
    for (int ts = 1; ts <= TC; ts++)
    {
        init();
        cout << "#" << ts << ' ' << solve() << '\n';
    }
    return 0;
}