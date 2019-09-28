// 더 맵게
// https://programmers.co.kr/learn/courses/30/lessons/42626
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto num : scoville)
    {
        pq.push(num);
    }

    while (pq.top() < K)
    {
        // pq 크기가 1인 경우
        if (pq.size() == 1)
        {
            answer = -1;
            break;
        }
        answer += 1;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int make = first + second * 2;
        pq.push(make);
    }

    if (pq.empty())
        answer = -1;
    return answer;
}
