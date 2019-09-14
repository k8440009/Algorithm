// 콜라츠 추측
#include <bits/stdc++.h>

using namespace std;

int solution(int num)
{
    int answer = 0;
    long long result = num;
    while (true)
    {
        if (result == 1)
            break;
        if (answer > 500)
        {
            answer = -1;
            break;
        }

        if (result % 2 == 0)
            result = result / 2;
        else
            result = result * 3 + 1;
        answer++;
    }

    return answer;
}