// 프린터
// https://programmers.co.kr/learn/courses/30/lessons/42587
// 풀이 -> 1.우선순위큐 O(N) O(N^2) 2. 정렬 O(N), O(1)
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, a, b) for (int i = a; i < b; i++)
int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>> q;
    rep1(i, 0, priorities.size())
    {
        q.push({priorities[i], i}); // 순위, 위치값
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
    int index = 0;
    int count = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        // 최고 순위와 현재 순위가 같으면
        if (priorities[index] == cur.first)
        {
            index++;
            count++;
            // 큐의 위치값과, 입력된 위치값이 같은 경우
            if (cur.second == location)
            {
                answer = count;
                break;
            }
        }
        else
            q.push({cur.first, cur.second});
    }
    return answer;
}