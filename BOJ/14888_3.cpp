// 연산자 끼워 넣기
// https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int N, M, MAX = -INF, MIN = INF;
vector <int> nums;

void calculate(int cnt, int sum, int plus, int minus, int mul, int div)
{
    if (cnt == N)
    {
        MAX = max(sum, MAX);
        MIN = min(sum, MIN);
        return ;
    }

    if (plus > 0)
        calculate(cnt + 1, sum + nums[cnt], plus - 1, minus, mul, div);
    if (minus > 0)
        calculate(cnt + 1, sum - nums[cnt], plus, minus - 1, mul, div);
    if (mul > 0)
        calculate(cnt + 1, sum * nums[cnt], plus, minus, mul - 1, div);
    if (div > 0)
        calculate(cnt + 1, sum / nums[cnt], plus, minus, mul, div - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;
    calculate(1, nums[0], plus, minus, mul, div);
    cout << MAX << '\n';
    cout << MIN << '\n';
}