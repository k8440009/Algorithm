// 이항 계수 2
// https://www.acmicpc.net/problem/11051
#include <iostream>
using namespace std;
const int MOD = 10007; // 모듈러 연산
const int MAX = 1000 + 1;
int visited[MAX][MAX];
int N, K;
// 이항 계수
int combination(int n, int k)
{
	if (k == 0 || n == k)
		return 1;
	int &cache = visited[n][k];
	if (cache != -1)
		return cache;
	return cache = (combination(n - 1, k - 1) % MOD + combination(n - 1, k) % MOD) % MOD;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill_n(visited[0], MAX * MAX, -1); // -1 로 초기화

	cin >> N >> K;
	cout << combination(N, K);
	return 0;
}
/*
	참고
	파스칼의 삼각형
	nCk = n-1Ck-1 + n-1Ck
*/