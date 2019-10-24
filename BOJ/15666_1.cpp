// N과 M (12)
// https://www.acmicpc.net/problem/15666
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> num;
vector<int> arr;
vector<vector<int>> answer;
void dfs(int index, int cnt, int prev)
{
    if (cnt == M)
    {
        answer.push_back(arr);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (num[i] >= prev)
        {

            arr.push_back(num[i]);
            dfs(i + 1, cnt + 1, num[i]);
            arr.pop_back();
        }
    }
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    num.resize(N);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num.begin(), num.end());
    // 1. 중복
    // 2. 비 내림차순
    dfs(0, 0, 0);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}