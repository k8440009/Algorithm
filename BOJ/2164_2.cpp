// 카드2
// https://www.acmicpc.net/problem/2164
#include <iostream>
#include <queue>
using namespace std;

int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// freopen("input.txt", "r", stdin);

	queue <int> q;
	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);
	while (q.size() != 1){
		// 맨 위를 바닥에 버린다.
		q.pop();
		// 맨위 카드를 아래로 옮긴다.
		int cur = q.front();
		q.pop();
		q.push(cur);
	}

	cout << q.front();
}