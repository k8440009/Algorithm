// 계단 오르기
// https://www.acmicpc.net/problem/2579
// https://github.com/kks227/BOJ/blob/master/2500/2579.cpp
#include <iostream>
using namespace std;

const int MAX = 300 + 1;
int N, answer;
int arr[MAX];
int dp[MAX];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < N; i++)
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	cout << dp[N - 1];
}

