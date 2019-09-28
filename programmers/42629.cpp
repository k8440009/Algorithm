#include <bits/stdc++.h>

using namespace std;
int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    int answer = 0;
    int total = stock;
    priority_queue<int> pq;

    int index = 0;
    for (int time = 0; time < k; time++)
    {

        if (time == dates[index])
        {
            pq.push(supplies[index]);
            index += 1;
        }

        if (total == 0)
        {
            total += pq.top();
            pq.pop();
            answer += 1;
        }

        total -= 1;
    }
    return answer;
}