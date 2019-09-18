// 하샤드 수
// https://programmers.co.kr/learn/courses/30/lessons/12947
#include <bits/stdc++.h>

using namespace std;

bool solution(int x)
{
    bool answer = true;
    int a = 0;
    int b = x;
    while (x > 0)
    {
        a += x % 10;
        x /= 10;
    }

    if (b % a != 0)
        answer = false;

    return answer;
}