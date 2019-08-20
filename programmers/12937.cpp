// 짝수 홀수
// https://programmers.co.kr/learn/courses/30/lessons/12937
#include <bits/stdc++.h>

using namespace std;

string solution(int num)
{
    string answer = "";
    if (num % 2 == 0)
        answer = "Even";
    else
        answer = "Odd";
    return answer;
}