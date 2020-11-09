#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

	for (int i = 0; i < arr.size(); i++)
	{
		int data = arr[i];
		
		if (data % divisor == 0)
			answer.push_back(data);
	}

	if (answer.size() == 0)
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());
    return answer;
}