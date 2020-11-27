// 피보나치 수 2
// https://www.acmicpc.net/problem/2748
#include <iostream>
using namespace std;

const int MAX = 90 + 1;
long long N;
long long cache[MAX];

long long pibo(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	
	if (cache[num] != -1)
		return cache[num];
	long long result = pibo(num - 1) + pibo(num - 2);
	cache[num] = result;
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	fill_n(cache, MAX, -1);
	cout << pibo(N);
	return 0;
}