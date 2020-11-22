// 순열장난
// https://www.acmicpc.net/problem/10597
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int used[51], maxN;
vector <string> numbers;
string str;

int getMaxValue(int size)
{
	if (size <= 9)
		return (size);
	
	int two = (size - 9) / 2;
	int quo = two / 10 + 1;
	int rest = two % 10 - 1;

	return (quo * 10 + rest);
}

void dfs(int idx, string src)
{
	if (idx < str.size())
	{
		src += str[idx];
		if (str[idx] == '0' && src.size() == 1)
			return;
	}
	else
	{
		for (int i = 0; i < numbers.size() - 1; i++)
			cout << numbers[i] << ' ';
		cout << numbers[numbers.size() -1];
		exit(0);
	}

	if (stoi(src) > maxN)
		return;

	if (!used[stoi(src)])
	{
		numbers.push_back(src);
		used[stoi(src)] = 1;
		dfs(idx + 1, "");
		used[stoi(src)] = 0;
		numbers.pop_back();
	}
	dfs(idx + 1, src);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> str;
	maxN = getMaxValue(str.size());
	dfs(0, "");
}