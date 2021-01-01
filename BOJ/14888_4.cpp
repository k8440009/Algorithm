// 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
using namespace std;

int N, answerMax, answerMin;
vector <int> datas;
int oper[4];

void dfs(int idx, int plus, int minus, int mul, int div, int total){
	if (idx == N){
		answerMax = max(answerMax, total);
		answerMin = min(answerMin, total);
		return ;
	}

	if (plus > 0)
		dfs(idx + 1, plus - 1, minus, mul, div, total + datas[idx]);
	if (minus > 0)
		dfs(idx + 1, plus, minus - 1, mul, div, total - datas[idx]);
	if (mul > 0)
		dfs(idx + 1, plus, minus, mul - 1, div, total * datas[idx]);
	if (div > 0)
		dfs(idx + 1, plus, minus, mul, div - 1, total / datas[idx]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	answerMax = -987654321, answerMin = 987654321;
	cin >> N;
	datas.resize(N);
	for (int i = 0; i < N; i++)
		cin >> datas[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	dfs(1, oper[0], oper[1], oper[2], oper[3], datas[0]);
	cout << answerMax << "\n" << answerMin;
}