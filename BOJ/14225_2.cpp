// 부분수열의 합
// https://www.acmicpc.net/problem/14225
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20 + 1;
int N, last = 0;
vector<int> number(N);
vector<int> answer;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> number[i];

    sort(number.begin(), number.end());
    // 인덱스, 갯수, 합계
    dfs(0, 0, 0);

    bool flag = false; // 배열 끝까지 가는 경우 체크
    last += 1;         // 최대값 + 1
    int i = 1;
    for (i = 1; i < answer.size() - 1; i++)
    {
        // 연속된 수열이 안되는 경우
        if (answer[i - 1] + 1 != answer[i])
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << answer[i - 1] + 1 << '\n';
    else
        cout << last << '\n';
    return 0;
}
*/