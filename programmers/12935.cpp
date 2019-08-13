// 제일 작은 수 제거하기
// https://programmers.co.kr/learn/courses/30/lessons/12935
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    if (arr.size() == 1)
    {
        answer.push_back(-1);
    }
    else
    {
        int del = *min_element(arr.begin(), arr.end());
        for (int num : arr)
        {
            if (num == del)
                continue;
            answer.push_back(num);
        }
    }
    return answer;
}