// 부등호
// https://www.acmicpc.net/problem/2529
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 10 + 1;
int K;
long long max_answer, min_answer;
string max_ans, min_ans;
vector <char> ine;

void dfs(int idx, int cur, int visited[MAX], vector<int> datas)
{

	if (idx == K)
	{
		string str = "";
		for (auto data : datas)
			str += (data + '0');
		if (min_answer > stol(str))
		{
			min_answer = stol(str);
			min_ans = str;
		}
		if (stol(str) > max_answer)
		{
			max_answer = stol(str);
			max_ans = str;
		}
		return ;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visited[i])
			continue;

		if (ine[idx] == '>')
		{
			if (cur > i)
			{
				datas.push_back(i);
				visited[i] = 1;
				dfs(idx + 1, i, visited, datas);
				visited[i] = 0;
				datas.pop_back();
			}
		}
		else
		{
			if (cur < i)
			{
				datas.push_back(i);
				visited[i] = 1;
				dfs(idx + 1, i, visited, datas);
				visited[i] = 0;
				datas.pop_back();
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		char tmp;
		cin >> tmp;
		ine.push_back(tmp);
	}

	max_answer = 0, min_answer = 10987654321;
	int visited[MAX];
	fill_n(visited, MAX, 0);

	vector<int> ans;
	for (int i = 0; i < 10; i++)
	{
		ans.push_back(i);
		visited[i] = 1;
		dfs(0, i, visited, ans);
		visited[i] = 0;
		ans.pop_back();

		ans.clear();
	}

	cout << max_ans << '\n';
	cout << min_ans << '\n';
}