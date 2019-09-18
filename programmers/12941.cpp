// 최솟값 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12941

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    for (auto num1 : A)
    {
        int result = 1000 * 1000 + 1;
        for (auto num2 : B)
        {
            result = min(result, num1 * num2);
        }

        answer += result;
    }
    return answer;
}