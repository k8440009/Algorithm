// 점수 계산
// https://www.acmicpc.net/problem/2822
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> score(8 + 1);
    for (int i = 1; i <= 8; i++)
    {
        score[i].first = i;
        cin >> score[i].second;
    }

    sort(score.begin() + 1, score.end(), cmp);

    vector<int> answer;
    int total = 0;
    for (int i = 4; i <= 8; i++)
    {
        total += score[i].second;
        answer.push_back(score[i].first);
    }
    cout << total << '\n';

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';

    return 0;
}