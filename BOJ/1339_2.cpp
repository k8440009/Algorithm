// 단어 수학
// https://www.acmicpc.net/problem/1339
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <string> strVec;
vector <char> alphaUsed;
int used[256];
long long answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	// 0 ~ 9
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		strVec.push_back(str);
		for (int j = 0; j < str.size(); j++)
		{
			if (!used[str[j]])
			{
				used[str[j]] = 1;
				alphaUsed.push_back(str[j]);
			}
		}
	}
	sort(alphaUsed.begin(), alphaUsed.end());
	string num = "9876543210";
	do
	{
		for (int i = 0; i < alphaUsed.size(); i++)
			used[alphaUsed[i]] = num[i] - '0';

		long long total = 0;
		for (string data : strVec)
		{
			int now = 0;
			for (int i = 0; i < data.size(); i++)
				now = now * 10 + used[data[i]];
			total += now;
		}
		answer = max(answer, total);
	} while (next_permutation(alphaUsed.begin(), alphaUsed.end()));
	cout << answer;
}