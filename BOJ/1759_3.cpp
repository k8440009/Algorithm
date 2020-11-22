// 암호 만들기
// https://www.acmicpc.net/problem/1759
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 15 + 1;
vector <char> vec;
int L, C;
int visited[MAX];

bool checkJa(char c)
{
	string str = "aeiou";
	for (int i = 0; i < 5; i++)
	{
		if (str[i] == c)
			return (true);
	}
	return (false);
}
void dfs(int idx, int ja, int mo, int cnt, vector <char> password)
{
	if (cnt == L)
	{
		if (ja >= 2 && mo >= 1)
		{
			for (auto c : password)
				cout << c;
			cout << '\n';
		}
		return ;
	}

	for (int i = idx; i < C; i++)
	{
		if (visited[i])
			continue;

		password.push_back(vec[i]);
		visited[i] = 1;
		if (checkJa(vec[i]))
			dfs(i, ja, mo + 1, cnt + 1, password);
		else
			dfs(i, ja + 1, mo, cnt + 1, password);
		password.pop_back();
		visited[i] = 0;
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> L >> C;
	vec.resize(C);
	for (int i = 0; i < C; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	vector <char> password;
	dfs(0, 0, 0, 0, password);
}