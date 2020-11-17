// 1로 만들기
// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> cache;

int findValue(int n)
{
	if (n == 1)
		return 0;
	
	if (cache[n] != -1)
		return (cache[n]);
	
	int result = findValue(n - 1) + 1;
	if (n % 3 == 0)
		result = min(findValue(n / 3) + 1, result);
	else if (n % 2 == 0)
		result = min(findValue(n / 2) + 1, result);
	cache[n] = result;
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N;

	cache.resize(N + 1, -1);

	cout << findValue(N);
}