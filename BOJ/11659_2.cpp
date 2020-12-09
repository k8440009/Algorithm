// 구간합 구하기 4
// https://www.acmicpc.net/problem/11659
#include <iostream>
using namespace std;

const int MAX = 100000 + 1;
int N, M;
int pSum[MAX];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		int num;
		cin >> num;
		pSum[i + 1] = pSum[i] + num; 
	}
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		cout << pSum[b] - pSum[a - 1] << '\n';
	}
}