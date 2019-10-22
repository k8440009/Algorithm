// N과 M (11)
// https://www.acmicpc.net/problem/15665
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 7;
int N, M;
vector<int> number;
vector<vector<int>> answer;
void dfs(int index, int cnt, vector<int> &permu)
{
    if (cnt == M)
    {
        answer.push_back(permu);
        return;
    }

    for (int i = 0; i < number.size(); i++)
    {
        permu.push_back(number[i]);
        dfs(i + 1, cnt + 1, permu);
        permu.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    number.resize(N);
    for (int i = 0; i < N; i++)
        cin >> number[i];

    sort(number.begin(), number.end());
    vector<int> permu;
    dfs(0, 0, permu);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}