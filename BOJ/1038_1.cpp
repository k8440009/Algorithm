// 감소하는 수
// https://www.acmicpc.net/problem/1038
#include <iostream>
#include <vector>
using namespace std;

int N;
int answer;
void dfs(int idx, vector <int> numbers, int digit)
{
	if (idx == digit)
	{
		answer++;
		if (answer == N)
		{
			for (int num : numbers)
				cout << num;
			exit(0);
		}
		return ;
	}

	for (int i = 0; i < 10; i++)
	{
		if (numbers[idx - 1] > i)
		{
			numbers.push_back(i);
			dfs(idx + 1, numbers, digit);
			numbers.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	if (N < 10)
		cout << N;
	else
	{
		answer += 9;
		vector <int> vec;
		// 9876543210 (최대값)
		for (int digit = 2; digit <= 10; digit++)
		{
			for (int i = 1; i <= 9; i++)
			{
				vec.push_back(i);
				dfs(1, vec, digit);
				vec.pop_back();
			}
		}
		cout << -1;
	}
	
}