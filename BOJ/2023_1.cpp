// 신기한 소수
// https://www.acmicpc.net/problem/2023
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int N;
vector <int> vec;
bool checkPrime(string str)
{
	int num = stoi(str);
	if (num == 0 || num == 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void dfs(int cnt, vector <int> prime, string str)
{
	if (cnt == N)
	{
		string str = "";
		for (int i = 0; i < prime.size(); i++)
		{
			str += prime[i] + '0';
			int num = stoi(str);
			if (!checkPrime(str))
				return ;
		}
		cout << str << '\n';
		return ;
	}

	for (int i = 0; i < 10; i++)
	{
		string newStr = str;
		newStr += (i + '0');
		if (checkPrime(newStr))
		{
			prime.push_back(i);
			dfs(cnt + 1, prime, newStr);
			prime.pop_back();	
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N;
	vec.resize(10);
	for (int i = 0; i < 10; i++)
		cin >> vec[i];

	vector <int> prime;
	for (int i = 1; i < 10; i++)
	{
		string str = "";
		str += (i + '0');
		if (checkPrime(str))
		{
			prime.push_back(i);
			dfs(1, prime, str);
			prime.pop_back();
		}
	}
}