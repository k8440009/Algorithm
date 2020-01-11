// 이항 계수 1
// https://www.acmicpc.net/problem/11050
#include <iostream>
using namespace std;
int N, K;
// 팩토리얼
int factorial(int n)
{
	// nCn = 1
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}
int bionomial(int n, int k)
{
	return factorial(n) / (factorial(k) * factorial(n - k));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	cout << bionomial(N, K);
	return 0;
}