// N과 M (11)
// https://www.acmicpc.net/problem/15665
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 7;
int N, M;
vector<int> num;
vector<int> arr;
vector<vector<int>> answer;
void dfs(int index, int cnt)
{
    if (cnt == M)
    {
        answer.push_back(arr);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        arr.push_back(num[i]);
        dfs(i + 1, cnt + 1);
        arr.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    sort(num.begin(), num.end());
    dfs(0, 0);

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