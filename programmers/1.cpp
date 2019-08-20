// 저울
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> weight)
{
    sort(weight.begin(), weight.end());

    int answer = 1;
    for (int num : weight)
    {
        if (answer < num)
            break;
        answer += num;
    }
    return answer;
}