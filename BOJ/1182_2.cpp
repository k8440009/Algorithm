// 부분수열의 합
// https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 50;
int N, S, answer;
vector<int> nums(MAX);
bool visited[MAX];
void recursive(int index, int total)
{
    if (index == N)
    {
        if (total == S)
            answer++;
        return;
    }

    recursive(index + 1, total + nums[index]);
    recursive(index + 1, total);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    recursive(0, 0);
    if (S == 0) // 공집합 제거
        answer -= 1;
    cout << answer << '\n';
}