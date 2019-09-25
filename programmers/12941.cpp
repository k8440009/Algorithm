// 최솟값 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12941

#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int j = A.size() - 1;
    for (int i = 0; i < A.size(); i++)
    {
        answer += (A[i] * B[j - i]);
    }
    return answer;
}