// 숫자의 표현
// https://programmers.co.kr/learn/courses/30/lessons/12924

#include <bits/stdc++.h>

using namespace std;

int N;
int cnt;

int solution(int n)
{
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum += j;
            if (sum > n)
                break;
            if (sum == n)
                answer++;
        }
    }
    return answer;
}
