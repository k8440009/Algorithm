// 실패율
// https://programmers.co.kr/learn/courses/30/lessons/42889
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, double> &a, pair<int, double> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    sort(stages.begin(), stages.end());
    vector<pair<int, double>> m2;
    int a, b;
    for (int i = 1; i <= N; i++)
    {
        a = 0;
        b = 0;
        for (int j = 0; j < stages.size(); j++)
        {
            if (stages[j] >= i)
                b++;
            if (stages[i] == i)
                a++;
        }
        if (a == 0)
            m2.push_back({i, 0});
        continue;

        double percent = (double)a / b;
        m2.push_back({i, percent});
    }

    sort(m2.begin(), m2.end(), cmp);

    for (int i = 0; i < m2.size(); i++)
    {
        answer.push_back(m2[i].first);
    }

    return answer;
}