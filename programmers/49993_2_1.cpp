// 스킬트리
// https://programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int is_set(char c, string set)
{
	int i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return 1;
	}
	return 0;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++)
	{
		bool flag = true;
		vector <char> data;
		string target = skill_trees[i];
		for (int j = 0; j < target.size(); j++)
		{
			if (is_set(target[j], skill) == 1)
				data.push_back(target[j]);
		}
        
        for (int k = 0; k < data.size(); k++)
        {
            if (skill[k] != data[k])
            {
                flag = false;
                break;
            }
        }
		answer += (flag) ? 1 : 0;
	}
    return answer;
}