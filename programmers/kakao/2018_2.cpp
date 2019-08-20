#include <bits/stdc++.h>

using namespace std;

/*
bool cmp(pair<double, int> &a, pair<double, int> &b)
{
    if (a.first == b.first)
        a.second > b.second;
    else
        a.first > b.first;
}
*/

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    sort(stages.begin(), stages.end());
    int total = 0;
    vector<pair<double, int>> fault(N + 1);
    int userSize = stages.size();
    int cnt = 0;
    int stageNum = 1;

    for (int stage : stages)
    {
        if (stage == stageNum)
            cnt++;
        else if (stage == N + 1)
        {
            fault[N].first = 0;
            fault[N].second = N;
        }
        else
        {
            if (cnt == 0)
            {
                fault[stageNum].first = 0;
                fault[stageNum].second = stageNum;
            }
            else
            {
                fault[stageNum].first = (double)((double)cnt / (double)userSize);
                fault[stageNum].second = stageNum;
            }
            stageNum++;
            userSize -= cnt;
            cnt = 0;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << fault[i].first << ' ' << fault[i].second << ' ';
        cout << '\n';
    }
    cout << '\n';

    return answer;
}