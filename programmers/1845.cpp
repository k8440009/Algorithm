// 폰켓몬
// https://programmers.co.kr/learn/courses/30/lessons/1845
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> hash;

    for (auto a : nums)
        hash[a]++;
    return min(hash.size(), nums.size() / 2);
}