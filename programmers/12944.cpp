// 평균 구하기
// https://programmers.co.kr/learn/courses/30/lessons/12944 <br/>
#include <bits/stdc++.h>
using namespace std;

double solution(vector<int> arr)
{
    double answer = 0;
    for (int num : arr)
        answer += num;
    answer /= arr.size();
    return answer;
}