// 부분수열의 합
// https://www.acmicpc.net/problem/14225
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<long long> num;
vector<long long> arr;
vector<long long> answer;
long long last = 0;
void dfs(int index, int cnt)
{
    if (cnt <= N)
    {
        long long total = 0;
        for (int i = 0; i < arr.size(); i++)
            total += num[arr[i]];
        answer.push_back(total);
        last = max(last, total);
    }
    else
        return;

    for (int i = index; i < N; i++)
    {
        arr.push_back(i);
        dfs(i + 1, cnt + 1);
        arr.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    num.resize(N);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num.begin(), num.end());

    // 재귀로 숫자 생성
    dfs(0, 0);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    last += 1;
    bool flag = false;
    long long i = 0;
    for (i = 0; i < answer.size() - 1; i++)
    {

        if (answer[i] + 1 != answer[i + 1])
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << answer[i] + 1 << '\n';
    else
        cout << last << '\n';

    return 0;
}