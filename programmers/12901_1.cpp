// 2016년
// https://programmers.co.kr/learn/courses/30/lessons/12901
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
	vector <string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	vector <int> date = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int total = 4;
	for (int i = 0; i < a - 1; i++)
		total += date[i];
	total += b;
	answer = day[total % 7];
    return answer;
}