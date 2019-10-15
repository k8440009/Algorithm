// 5658 [모의 SW 역량테스트] 보물상자 비밀번호
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 28;
int N, K;
int board[MAX];
vector<long long> numbers;
void rotate()
{
    int temp = board[N - 1];
    for (int i = N - 1; i - 1 >= 0; i--)
    {
        board[i] = board[i - 1];
    }
    board[0] = temp;
}
void check()
{
    int mod = N / 4;
    // 4방향
    for (int i = 0; i < 4; i++)
    {
        int start = i * mod;
        int number = 0;
        for (int j = 0; j < mod; j++)
        {
            number += (board[start + j] * pow(16, (mod - 1) - j));
        }
        numbers.push_back(number);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        fill_n(board, MAX, 0);
        string str;
        cin >> N >> K;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'F')
            {
                board[i] = str[i] - 'A' + 10;
            }
            else
            {
                board[i] = str[i] - '0';
            }
        }

        int mod = N / 4;

        check();

        for (int i = 0; i < mod - 1; i++)
        {
            rotate();
            check();
        }

        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
        sort(numbers.begin(), numbers.end(), greater<long long>());

        cout << "#" << ts << ' ' << numbers[K - 1] << '\n';
        numbers.clear();
    }

    return 0;
}