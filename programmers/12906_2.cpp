// 같은 숫자는 싫어
// https://programmers.co.kr/learn/courses/30/lessons/12906
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
	vector <int> answer;
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	answer = arr;
    return answer;
}

/*
	참고
	https://dpdpwl.tistory.com/39
*/