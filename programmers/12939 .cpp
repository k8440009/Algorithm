// 최댓값과 최솟값
// https://programmers.co.kr/learn/courses/30/lessons/12939
#include <bits/stdc++.h>
using namespace std;

string solution(string s)
{
    string answer = "";
    stringstream ss;
    ss.str(s);
    vector<int> v;
    int num;
    while (ss >> num)
    {
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size() - 1]);

    return answer;
}