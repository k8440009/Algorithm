// K 번째 수
// https://programmers.co.kr/learn/courses/30/lessons/42748
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
	for (int i = 0; i < commands.size(); i++)
	{
		int start = commands[i][0] - 1;
		int end = commands[i][1] - 1;
		int pos = commands[i][2] - 1;

		vector <int> new_arr;
		for (int j = start; j <= end; j++)
			new_arr.push_back(array[j]);
		sort(new_arr.begin(), new_arr.end());
		answer.push_back(new_arr[pos]);
	}
    return answer;
}