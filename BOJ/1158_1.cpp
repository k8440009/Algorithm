// 요세푸스 문제
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N >> K;

	queue <int> q;
	vector <int> datas;
	for (int i = 1; i <= N; i++)
		q.push(i);
	
	int cnt = 1;
	while (!q.empty()){

		if (cnt == K){
			int del = q.front();
			q.pop();
			datas.push_back(del);
			cnt = 1;
		}
		else{
			int cur = q.front();
			q.pop();
			q.push(cur);
			++cnt;
		}
	}
	cout << "<";
	for (int i = 0; i < datas.size(); i++){
		if (i == datas.size() - 1)
			cout << datas[i];
		else
			cout << datas[i] << ", ";
	}
	cout << ">";
}