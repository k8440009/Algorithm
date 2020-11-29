// 리모컨
// https://www.acmicpc.net/problem/1107
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string N;
int M;
int broken[10];
int answer;
int base;
void dfs(int idx, string num){

	if (idx > 0 && idx <= base){
		int n = stoi(num);
		answer = min(answer, abs(n - stoi(N)) + idx);
		if (idx == base)
			return;
	}


	for (int i = 0; i < 10; i++){
		if (broken[i])
			continue;
		
		string tmp = num;
		tmp += (i + '0');
		dfs (idx + 1, tmp);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++){
		int b;
		cin >> b;
		broken[b] = 1;
	}
	// 시작점
	answer = abs(100 - stoi(N));
	base = N.size() + 1;
	dfs(0, "");
	cout << answer;
}